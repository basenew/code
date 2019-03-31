#include "utility.h"
#include <thread>
#include <vector>

using namespace std;

class client
{
public:
	client(int id):_id(id), _fd(-1), _port(0){};
	~client(){};
	void start();
	void stop();
	void stat();
	int connect(const string& ip, unsigned short port);
	int send(const char* msg, int len);
private:
	int _cnt;
	int _snded;
	int _rcved;
	int _fd;
	int _id;
	string _ip;
	unsigned short _port;
};

int client::connect(const string& ip, unsigned short port)
{
	if (_fd == -1)
	{
		_fd = socket(PF_INET, SOCK_STREAM, 0);
		if (-1 == _fd)
		{
			cout << "socket err:" << errno << endl;
			return errno;
		}
	}

	struct sockaddr_in dst_addr;
	dst_addr.sin_family = PF_INET;
	dst_addr.sin_port = htons(port);
	dst_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	
	int ret = ::connect(_fd, (struct sockaddr*)&dst_addr, sizeof(dst_addr));
	if (ret >= 0)
	{
		cout << _id << " connect succ" << endl;
		return 0;
	}
	else
	{
		close(_fd);
		_fd = -1;
		cout << _id << " connect err:" << errno << endl;
	}
	return errno;
}


class tester
{
public:
	tester(const string& ip, unsigned short port, int cnt):_ip(ip), _port(port), _cnt(cnt), _t(nullptr){};
	~tester(){if (_t != nullptr) delete _t;};
	void start();
	void stop(){};
private:
	static void thread_loop(tester* t){t->loop();};
	void loop();
	int _cnt;
	int _state;
	string _ip;
	unsigned short _port;
	vector<client> _clients;
	thread* _t;
	thread::id _tid;
};

void tester::start()
{
	_t = new thread(thread_loop, this);
	_tid = _t->get_id();
	for (int i = 0; i < _cnt; i++)
		_clients.push_back(client(i));
	_state = 1;
	_t->detach();
}

void tester::loop()
{
	cout << "start to connect " << _cnt << " link" << endl;
	int succ_cnt = 0, fail_cnt = 0;

	while(_state)
	{
		if (succ_cnt == _cnt)
			break;
		if (0 == _clients[succ_cnt].connect(_ip, _port))
			succ_cnt++;
		else
			fail_cnt++;
			
	}
	cout << "finished" << endl;
	cout << "succ:" << succ_cnt << endl;
	cout << "fail:" << fail_cnt << endl;
}

int main(int argc, char** argv)
{
	int count = 100;
	int tester_count = 1;
	string ip("127.0.0.1");
	unsigned short port = 8888;

	if (argc == 2)
		tester_count = atoi(argv[1]);
	else if (argc == 3)
	{
		tester_count = atoi(argv[1]);
		count = atoi(argv[2]);
	}
	else if (argc > 3)
	{
		tester_count = atoi(argv[1]);
		count = atoi(argv[2]);
		ip = argv[3];
		port = atoi(argv[4]);
	}	
	
	vector<tester*> vt;

	for (int i = 0; i < tester_count; i++)
	{
		tester* t = new tester(ip, port, count);
		t->start();
		vt.push_back(t);
	}

	while('q' == getchar())
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	for (auto t:vt)
	{
		delete t;
	}
	return 0;
}

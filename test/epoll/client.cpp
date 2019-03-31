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


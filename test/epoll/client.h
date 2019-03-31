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



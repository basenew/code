#include "../comm/comm.h"
#include "epoll_reactor.h"
#include "tcp_acceptor.h"
#include "server_frame.h"

#define TEST_MAIN main

using namespace comm;

class server:public server_frame
{
public:
	server():server_frame(_reactor, _acceptor){};
	~server(){};
	int send_sig(int sig)
	{
		LOG_DBG << "send_sig" << endl;
		return Err::OK;
	};

	int on_start()
	{
		LOG_DBG << "on_start" << endl;
		return Err::OK;
	};

	int on_stop()
	{
		LOG_DBG << "on_stop" << endl;
		return Err::OK;
	};

	int on_suspend()
	{
		LOG_DBG << "on_suspend" << endl;
		return Err::OK;
	};

	int on_continue()
	{
		LOG_DBG << "on_continue" << endl;
		return Err::OK;
	};

	int on_reload()
	{
		LOG_DBG << "on_reload" << endl;
		return Err::OK;
	};

private:
	tcp_acceptor _acceptor;
	epoll_reactor _reactor;
};

int main(int argc, char** argv)
{
	LOG_DBG<< "test server frame" << endl;
	server svr;

	return 0;
}

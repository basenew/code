#include "../../comm/sys/includes.h"
#include "../../comm/network/server_frame.h"
#include "../../comm/network/socketop.h"
#include "../../comm/network/epoll_reactor.h"
#include "../../comm/network/tcp_acceptor.h"
#include "../../comm/network/tcp_transmitter.h"
#include "../../comm/mem_pool/vector_list.h"

#include <list>

using namespace std;
using namespace comm;

class echo_server:public server_frame
{
public:
	echo_server():server_frame(_reactor, _acceptor){};
	~echo_server();	


	int start(int argc, char** argv)
	{
		LOG_SYS << "echo_server start..." << endl;
		using std::placeholders::_1 ;
		using std::placeholders::_2 ;
    		accept_cb cb = std::bind(&on_connected,this,_1,_2);
		_acceptor.open("127.0.0.1", 9898, cb);
		return 0;
	};

	static int on_connected(int fd, sockaddr_in* addr)
	{
		LOG_MSG << "connected:" << trans_straddr(addr) << ":" << addr.sin_port << endl;
		tcp_transmitter* client = new tcp_transmitter;	
		client->open(fd);
		_reactor.add_handler(client, reactor::event::READ|reactor::event::WRITE);
		_clients.push_back(client);
	};

protected:
	void on_start(){};
	void on_stop(){};
	void on_suspend(){};
	void on_continue(){};
	void on_reload(){};
private:
	tcp_acceptor _acceptor;
	epoll_reactor _reactor;
	
	list<io_handler*> _clients;
};

int main(int argc, char** argv)
{
	echo_server svr;
	svr.start(argc, argv);
	
	return 0;
}


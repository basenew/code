#pragma once
#include <functional>
#include <memory>

namespace dvc{

class NetEngine{
using std::shared_ptr;

using Reader = function<int(shared_ptr<char> pbuf, int len)>;
using Writer = function<int(shared_ptr<char> pbuf, int len)>;
using Acceptor = function<int(int fd)>;
using Connector = function<int(int err)>;
using Timer = function<void()>;

public:
	int init(uint32_t thread_num);
	int run();
	int stop();

	void set_reader(Reader reader);
	void set_writer(Writer writer);
	void set_connector(Connector connector);
	void set_acceptor(Acceptor acceptor);

	int add_timer(Timer timer); 
	int del_timer(int time_id); 

private:
};

}


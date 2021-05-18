#pragma once

namespace dvc{

class Net{
public:
	int init(uint32_t thread_num);
	int connect(const string& ip, uint16_t port);
};

}


#pragma once
/*
 */

namespace dvc{
class Buffer{
public:
    Buffer();
    ~Buffer();
private:
	int cur_size;
	int need_size;
};
}


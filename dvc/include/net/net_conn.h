#pragma once

#include <memory>

namespace dvc{

class Connector{
using std::shared_ptr;
public:
    int open(const string& remote_ip, uint16_t remote_port); 
    int close(); 
    int write();

    int on_read(shared_ptr<char> buf, int len);
    int on_write(shared_ptr<char> buf, int len);
    int on_connect(int err);

    const string& remote_ip();
    uint16_t remote_port();

    const string& local_ip();
    uint16_t local_port();

private:
    int fd;
    string remote_ip_;
    uint16_t remote_port_;

    string local_ip_;
    uint16_t local_port_;
};

}


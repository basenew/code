#pragma once

namespace dvc{

class Connector{
public:
    int open(const string& peer_ip, uint16_t peer_port); 
    int close(); 
    int write();

    void on_read();
    void on_write();
    void on_connect();
    void on_disconnect();

private:
    string peer_ip_;
    uint16_t peer_port_;
};

}

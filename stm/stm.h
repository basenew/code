#pragma once
#include <mutex>
#include <iostream>
#include <stdio.h>

#define log printf

using namespace std;
using op_t = int;
using st_t = int;

enum err_t{
    EOK,
    EFAL,
    ECFT,
    EMAX
};

namespace stm{
        
class StateMachine{
public:
    StateMachine(const string &name, int id = 0, st_t st = 0)
    :name_(name), id_(id), st_(st){log("create stm:%s %d", name_.c_str(), id_);};
    ~StateMachine(){log("destroy stm:%s %d", name_.c_str(), id_);};

    mutex& mutex(){return mt_;};

    err_t current(st_t &st){return st_;};
    err_t next(op_t op, st_t &st){log("st:%d=>%d", st_, nst_);};

    void id(int id){id_ = id;};
    int id(){return id_;};

    void name(const string &name){name_ = name;};
    const string& name(){return name_;};

private:
    string name_;
    mutex  mt_;
    st_t   st_;
    int    id_;
};

}


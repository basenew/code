#pragma once

#include <iostream>
#include <queue>
#include <mutex>
#include <future>
#include <functional>
#include <condition_variable>

using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::bind;
using std::mutex;
using std::future;
using std::forward;
using std::function;
using std::condition_variable;

namespace dvc{
class TaskPool{
public:
	TaskPool(unsigned int thread_num = 1)
    :shutdown_(false)
    ,thread_num_(thread_num)
    ,workers_(thread_num){
        auto worker = [this](mutex& mtx, condition_variable& cv, bool& ready){
            function<void()> t;

            {
                unique_lock<mutex> lock(mtx);
                ready = true;
                cv.notify_one();
            }

            do{
                {
                    unique_lock<mutex> lock(mtx_);
                    cout << "waiting for task" << endl;
                    while(!shutdown_ && tasks_.empty())cv_.wait(lock);
                    if(shutdown_)break;

                    t = tasks_.front();
                    tasks_.pop();
                }

                t(); 
            }while(!shutdown_);
            cout << "worker exit" << endl;
        };

        bool ready;
        mutex mtx;
        condition_variable cv;
        for(unsigned int i = 0; i < thread_num_; i++){
            ready = false;
            unique_lock<mutex> lock(mtx);
            workers_.at(i) = thread(worker, ref(mtx), ref(cv), ref(ready));
            while(!ready)cv.wait(lock);
            cout << "worker ready:" << i << endl;
        }
    };

    ~TaskPool(){cout << __FUNCTION__ << endl;shutdown();};

    void shutdown(){
        cout << __FUNCTION__ << endl;
        {
            unique_lock<mutex> lock(mtx_);
            if(shutdown_) return;

            shutdown_ = true;
            cv_.notify_all();
        }

        for(auto& w:workers_)
            if(w.joinable()) w.join();
    };

    template<typename T, typename... Args>
	void push(T&& t, Args&& ...args){
        function<decltype(t(args...))()> f = bind(forward<T>(t), forward<Args>(args)...);
        unique_lock<mutex> lock(mtx_);
        tasks_.emplace([f](){f();});
        cv_.notify_one();
    };

    template<typename T, typename... Args>
	auto push_ack(T&& t, Args&& ...args) -> future<decltype(t(args...))>{
        function<decltype(t(args...))()> f = bind(forward<T>(t), forward<Args>(args)...);
        auto pf = make_shared<packaged_task<decltype(t(args...))()>>(f);

        unique_lock<mutex> lock(mtx_);
        tasks_.emplace([pf](){(*pf)();});
        cv_.notify_one();

        return pf->get_future();
    };

private:
    bool shutdown_;
    unsigned int thread_num_;

    mutex mtx_;
    vector<thread> workers_;
    condition_variable cv_;
    queue<function<void()>> tasks_;
};
}


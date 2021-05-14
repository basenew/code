// test.cpp
#include <iostream>
#include <random>
#include "thread_pool.h"

using namespace std;
std::random_device rd; // 真实随机数产生器
std::mt19937 mt(rd()); //生成计算随机数mt
std::uniform_int_distribution<int> dist(-1000, 1000); //生成-1000到1000之间的离散均匀分布数
auto rnd = std::bind(dist, mt);

// 设置线程睡眠时间
void simulate_hard_computation()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000 + rnd()));
}

// 添加两个数字的简单函数并打印结果
void multiply(const int a, const int b)
{
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
}

// 添加并输出结果
void multiply_output(int &out, const int a, const int b)
{
    simulate_hard_computation();
    out = a * b;
    std::cout << a << " * " << b << " = " << out << std::endl;
}

// 结果返回
int multiply_return(const int a, const int b)
{
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
    return res;
}


void example()
{
    // 创建3个线程的线程池
    ThreadPool pool(3);
    // 初始化线程池
    pool.init();
    // 提交乘法操作，总共30个
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 10; ++j)
        {
            pool.submit(multiply, i, j);
        }
    // 使用ref传递的输出参数提交函数
    int output_ref;
    auto future1 = pool.submit(multiply_output, std::ref(output_ref), 5, 6);
    // 等待乘法输出完成
    future1.get();
    std::cout << "Last operation result is equals to " << output_ref << std::endl;
    // 使用return参数提交函数
    auto future2 = pool.submit(multiply_return, 5, 3);
    // 等待乘法输出完成
    int res = future2.get();
    std::cout << "Last operation result is equals to " << res << std::endl;
    // 关闭线程池
    pool.shutdown();
}
#include "task_pool.h"
int main()
{
    dvc::TaskPool task_pool(10);
    task_pool.push([](){std::cout<<"taskpool task"<<std::endl;});
    auto f = task_pool.push_ack([](int a, int b)->int{return a+b;}, 5, 3);
    int sum = f.get();
    cout << "sum:" << sum << endl;
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    //example();
}
#if 0
#define START_RECORD_TIME() \
    auto start = std::chrono::steady_clock::now()

#define END_RECORD_TIME() \
    auto end = std::chrono::steady_clock::now();\
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>(end-start);\
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n"

void test_single_thread(const float f, const int times){
	START_RECORD_TIME();
    double res = 0.0;
	for(int i = 0; i < times; i++){
		res += f*f;
		cout << "******************************************************************************************************" << endl;
	}
	END_RECORD_TIME();
}

void test_thread_pool(const float f, const int times, const int threads)
{
	auto func = [](const float f1, int sub_times){
		double res = 0.0;
		for(int i = 0; i < sub_times)
			res += f*f;
	}
	START_RECORD_TIME();
    ThreadPool pool(threads);
    pool.init();
	for (int i = 0; i < threads; i++)
    	pool.submit(func, f, times/threads);
    pool.shutdown();
	END_RECORD_TIME();
}
int main()
{
	if (argc > 2){
		int m = atoi(argv[1]);
		int f = atoi(argv[2]);
		int times = autoi(argv[3]);
		int threads = autoi(argv[4]);
		if (m != 0){
			test_thread_pool(f, times, threads);
		}else{
			test_single_thread(f, times);
		}	
	}else{
    	example();
	}

    return 0;
}
#endif

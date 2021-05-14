#include "res.h"
#include <memory>

void call_shared_ptr(shared_ptr<Res> pres){
    INFUNC();
    cout << *pres << " ref count:" << pres.use_count() << endl;//增加管理资源的引用计数
    OUTFUNC();
}

void test_shared_ptr(){
    INFUNC();
	{
		shared_ptr<Res> pres(new Res("res1"));//定义的时候直接绑定了资源指针
        cout << *pres << " ref count:" << pres.use_count() << endl;
		pres.reset(new Res("res2"));          //reset的时候递减旧资源的引用计数，可以触发释放资源
        cout << *pres << " ref count:" << pres.use_count() << endl;
		getchar();
        call_shared_ptr(pres);
        cout << *pres << " ref count:" << pres.use_count() << endl;
	}
    OUTFUNC();
}

void test_unique_ptr(){
    INFUNC();
    unique_ptr<Res> pres(new Res("res1"));
    //unique_ptr<Res> pres2(pres);          //error 删除拷贝构造函数来达到唯一拥有资源
    //unique_ptr<Res> pres2 = pres;         //error
    pres.reset(new Res("res1"));
    OUTFUNC();
}

void test_weak_ptr(){
    shared_ptr<Res> pr(new Res("res"));
    shared_ptr<WeakRes> pwr(new WeakRes("wres", pr));
    pr->set_weak_res(pwr); 
}

int main(){
	//test_shared_ptr();
	//test_unique_ptr();
	test_weak_ptr();
	getchar();
	return 0;
}

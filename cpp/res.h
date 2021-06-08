#pragma once
#include "utils.h"
#include <memory>

class WeakRes;
class Res{
public:
	friend ostream& operator<<(ostream& o, Res& res){
		o << res.name_;
	};

	Res(const string& name=""):name_(name){
		INFUNC();
		cout << name_ << endl;
		OUTFUNC();
	};
#if 0
	virtual ~Res(){
		INFUNC();
		cout << name_ << endl;
		OUTFUNC();
	};
#endif

	void set_weak_res(shared_ptr<WeakRes> pwres){pwres_ = pwres;};
private:
	string name_;
	shared_ptr<WeakRes> pwres_;
};

class ResEx:public Res{
public:
    virtual void vfunc(){};
};

class WeakRes:public Res{
public:
	WeakRes(const string& name, shared_ptr<Res> res):Res(name), pres(res){};
private:
	//shared_ptr<Res> pres;//error not free res memory leak 
	weak_ptr<Res> pres;
};


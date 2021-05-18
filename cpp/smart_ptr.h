#pragma once

template<class T>
class smart_ptr{
public:
	smart_ptr(T* p = nullptr):_p(p){};
	~smart_ptr(){if (_p)delete _p;};
	//smart_ptr(smart_ptr& other) = delete;
	smart_ptr& operator=(smart_ptr& other) = delete;

	T* operator->(){return _p;};
	T& operator*(){return *_p;};
	operator bool(){return _p;};

private:
	T* _p;
};


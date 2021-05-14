#pragma once

#include <iostream>
#include <list>


namespace tsfl{

using namespace std;

#define INVALID_ID (-1)

enum TaskType{
	TSK,
	FLW
};

enum TaskStatus{
	IDL,
	RNG,
	PSD,
	FIN
};

class Task{
public:
	Task()
	:_id()
	int id(){return _id;};
	int idx(){return _idx;};
	int thd_id(){return _thd_id;};
	int pre(){return _pre_id;};
	int nxt(){return _nxt_id;};
	const string& name(){return _name;};
	TaskType type(){return _type;};
	TaskStatus status(){return _st;};

private:
	int _id;
	int _idx;
	int _thd_id;
	int _pre_id;
	int _nxt_id;

	string name;
	TaskType _type;
	TaskStatus _st;
};

class TaskFlow:public Task{
public:
	TaskFlow();
	virtual ~TaskFlow();
};
}


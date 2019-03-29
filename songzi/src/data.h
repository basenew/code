#pragma once
#include <assert.h>
#include <string.h>
#include <map>

using namespace std;

enum{male = 1,female = 0};
struct DataType;
using DataTypes = map<string, DataType*>;
using DataTypesIt = map<string, DataType*>::iterator;

struct VarStr
{
	VarStr():data(NULL){};
	VarStr(const string& str)
	{
		data = new char[str.length() + 1];
		strcpy(data, str.c_str());
		cout << "1:" << data << endl;
	};
	VarStr(const char* str)
	{
		data = new char[strlen(str) + 1];
		strcpy(data, str);
		cout << "2:" << data << endl;
	};
	VarStr(const VarStr& str)
	{
		data = new char[strlen(str.data) + 1];
		strcpy(data, str.data);
		cout << "3:" << data << endl;
	};
	~VarStr()
	{
		if (data) 
		{
			cout << "del:" << data << endl;
			delete[] data;
			data = nullptr;
		}
	};

	VarStr& operator=(const VarStr& str)
	{
		if (this == &str) return *this;
		if (data) delete[] data;
		
		data = new char[strlen(str.data) + 1];
		strcpy(data, str.data);
		cout << "4:" << data << endl;
		return *this;
	};
	VarStr& operator=(const string& str)
	{
		if (data) delete[] data;
		data = new char[str.length() + 1];
		strcpy(data, str.c_str());
		cout << "5:" << data << endl;
		return *this;
	};
	VarStr& operator=(const char* str)
	{
		if (data) delete[] data;
		
		data = new char[strlen(str) + 1];
		strcpy(data, str);
		cout << "6:" << data << endl;
		return *this;
	};

	int length()
	{
		return strlen(data);
	};

	string str(){return string(data);};
	char* data;
};

class Data
{
public:
	Data(const string& name, int id):_data_name(name), _id(id), _fields_set(0){};
	Data(const string& name):_id(0), _data_name(name), _fields_set(0){};
	Data(const Data& data):_id(data._id), _data_name(data._data_name), _fields_set(data._fields_set){};
	Data& operator=(const Data& data)
	{
		if (&data == this) return *this;
		_id = data._id;
		_fields_set = data._fields_set;
		_data_name = data._data_name;
	};
	virtual ~Data(){};
	int id()const{return _id;};
	void set_id(int id){_id = id;};
	string data_name() const {return _data_name.data;};
//	VarStr& data_name(){return _data_name;};
	void data_name(const string& name){_data_name = name;};
	void data_name(const VarStr& name){_data_name = name;};
	virtual inline ostream& operator<<(ostream& o){return o;};
	bool set_field(int idx)
	{
		if (idx < sizeof (_fields_set) * 8) 
		{
			_fields_set |= (1 << idx);
			return true;
		}

		cout << "invalid idx:" << idx << endl;
		return false;
	};
	bool get_field(int idx)const
	{
		return _fields_set & (1 << idx);
	};

private:
	int    _id;
	int    _fields_set;
	VarStr _data_name;
};

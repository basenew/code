#pragma once
#include <vector>
#include <map>
//#include <cppcms/json.h>

#include "conn_pool.h"
#include "data.h"


using namespace std;


class DataMgr
{
private:
	DataMgr(){};
public:
	static DataMgr& get_ins(){return _ins;};
	bool init(const DBCnf& db_cnf, int conn_cnt);
	void release();
	bool get(Data& data);
	bool add(Data& data);
	bool del(const Data& data);
	bool update(Data& data);
	bool to_json(const Data& data, string& json);
	bool from_json(Data& data, const string& json);
private:
	static DataMgr _ins;
	DataTypes _data_types;
	ConnPool  _conns;
};


#define data_mgr DataMgr::get_ins()

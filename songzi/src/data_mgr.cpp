#pragma once
#include "data_mgr.h"
#include <sstream>
#include <cppcms/json.h>

using namespace std;
using namespace cppcms::json;

enum EFLDT
{
	ENONE,
	EBIT,
	EBYTE,
	EWORD,
	EDWRD,
	EQWRD,
	EBINA,
	ESTR,
	EOBJ,
	EARR,
};

DataMgr DataMgr::_ins;
static const char type_size[]{1, 1, 1, 2, 4, 8, 8, 8, 8, 8};
struct Field
{
	Field(const string& field_name, const string& type_name, unsigned char index, unsigned char prev_offset):
		name(field_name),
		type(get_type(type_name)),
		idx(index),
		offset(prev_offset)
	{};

	EFLDT get_type(const string& type_name)
	{
		if (type_name.find("tinyint") != string::npos)
		  return EBYTE;
		else if (type_name == "")
		  return EWORD;
		else if (type_name.find("int") != string::npos)
		  return EDWRD;
		else if (type_name == "")
		  return EQWRD;
		else if (type_name.find("varchar") != string::npos)
		  return ESTR;

		return ENONE;
	};
	/*
	   inline ostream& operator<<(ostream& o)
	   {
	   o << "(" << idx << "," << name << "," << type << "," << offset << ")";
	   return o;
	   }
	   */

	string name;
	EFLDT  type;
	int idx;
	int offset;
};

struct DataType
{
	DataType(const string& data_name):name(data_name){};
	DataType(){};
	bool parse_json(const string& json_data);
	string name;
	vector<Field> fields;
	/*
	   inline ostream& operator<<(ostream& o)
	   {
	   o << name << ":{" << endl;
	   for (auto f:fields)
	   {
	   o << "(" << f.idx << "," << f.name << "," << f.type << "," << f.offset << ")";
	//o << f << endl; 
	}
	o << "}";
	return o;
	};*/
	friend ostream& operator<<(ostream& o, const DataType& data_type);
};

stringstream& append(stringstream& ss, EFLDT type, const void* data)
//ostream& operator<<(ostream ss, const void* data)
{
	switch(type)
	{
		case EBYTE:
			{
				unsigned char v = *(unsigned char*)data;
				ss << (int)v;
			}
			break;
		case EWORD:
			{
				unsigned short v = *(unsigned short*)data;
				ss << (int)v;
			}
			break;
		case EDWRD:
			{
				unsigned int v = *(unsigned int*)data;
				ss << (int)v;
			}
			break;
		case EQWRD:
			{
				unsigned long v = *(unsigned long*)data;
				ss << (long)v;
			}
			break;
		case ESTR:
			{
				string str(*(char**)data);
				ss << "'" << str << "'";
			}
			break;
		default:
			cout << "invalid type:" << type << endl;
			break;
	}
	return ss;
}

ostream& operator<<(ostream& o, const DataType& data_type)
{
	o << data_type.name << "xx:{" << endl;
	for (auto f:data_type.fields)
	{
		o << "(" << f.idx << "," << f.name << "," << f.type << "," << f.offset << ")" << endl;
	}
	o << "}";
	return o;
}

void set_json_value(value& v, const string& name, EFLDT t, const void* data)
{
	switch(t)
	{
		case ESTR:
			{
				v[name] = string(*(char**)data);
			}
			break;
		case EBYTE:
			{
				v[name] = *(unsigned char*)data;
			}
			break;
		case EWORD:
			{
				v[name] = *(unsigned short*)data;
			}
			break;
		case EDWRD:
			{
				v[name] = *(unsigned int*)data;
			}
			break;
		case EQWRD:
			{
				v[name] = *(unsigned long*)data;
			}
			break;
		default:
			cout << "invalid type:" << t << endl;
			break;
	}
}

void set_db_value(const char* v, const string& name, EFLDT t, const void* data)
{
	switch(t)
	{
		case ESTR:
			{
				VarStr& str = *(VarStr*)data;
				str = v;
			}
			break;
		case EBYTE:
			{
				*(unsigned char*)data = atoi(v);
			}
			break;
		case EWORD:
			{
				*(unsigned short*)data = atoi(v);
			}
			break;
		case EDWRD:
			{
				*(unsigned int*)data = atoi(v);
			}
			break;
		case EQWRD:
			{
				*(unsigned long*)data = atol(v);
			}
			break;
		default:
			cout << "invalid type:" << t << endl;
			break;
	}
}

bool get_json_value(const value& v, const string& name, EFLDT t, void* data)
{
	const value& it = v.find(name);
	if (it.is_undefined())
	{
		cout << "not found:" << name << endl;
		return false;
	}

	switch(t)
	{
		case ESTR:
			{
				VarStr& str = *(VarStr*)data;
				str = it.str();
//				char* str = *(char**)data;
//				str = new char[it.str().length() + 1];
//				strcpy(str, it.str().c_str());
//				cout << "parse:" << str << endl;
			}
			break;
		case EBYTE:
			{
				*(unsigned char*)data = it.number();
			}
			break;
		case EWORD:
			{
				*(unsigned short*)data = it.number();
			}
			break;
		case EDWRD:
			{
				*(unsigned int*)data = it.number();
			}
			break;
		case EQWRD:
			{
				*(unsigned long*)data = it.number();
			}
			break;
		default:
			cout << "invalid type:" << t << endl;
			break;
	}
	return true;
}

bool DataMgr::to_json(const Data& data, string& json_data)
{
	cout << "DataMgr::to_json" << endl;
	auto it = _data_types.find(data.data_name());
	if (it == _data_types.end())
	{
		cout << "unknow type:" << data.data_name() << endl;
		return false;
	}

	value json;
	DataType& data_type = *it->second;
	for (auto f:data_type.fields)
	{
		set_json_value(json, f.name, f.type, (char*)&data + f.offset);
	}
	json_data = json.save();

	return true;
}

bool DataMgr::init(const DBCnf& db_cnf, int conn_cnt)
{
	cout << "DataMgr::init" << endl;
	if (!_conns.init(conn_cnt, db_cnf)) return false;

	DBConn conn = _conns.pop();
	if (!conn) return false;

	if (0 != mysql_query(conn, "show tables"))
	{
		MYSQL_ERR();
		_conns.push(conn);
		return false;
	}

	MYSQL_RES*   res;
	MYSQL_FIELD* field;
	MYSQL_ROW    row;

	res = mysql_store_result(conn);
	if (NULL == res)
	{
		MYSQL_ERR();
		_conns.push(conn);
		return false;
	}

	while (true)
	{
		row = mysql_fetch_row(res);
		if (NULL == row || NULL == row[0]) break;

		cout << "table:" << row[0] << endl;
		_data_types[string(row[0])] = new DataType(row[0]);
	}

	string show_field_prefix("show columns from ");
	for (auto it:_data_types)
	{
		string show_fields = show_field_prefix + it.first;
		if (0 != mysql_query(conn, show_fields.c_str()))
		{
			MYSQL_ERR();
			continue;
		}

		res = mysql_store_result(conn);
		if (NULL == res)
		{
			MYSQL_ERR();
			continue;
		}

		DataType& data_type = *it.second;
		unsigned char idx = 0;
		unsigned char prev_offset = sizeof(Data);
		while(true)
		{
			row = mysql_fetch_row(res);
			if (NULL == row || NULL == row[0]) break;

			Field f(row[0], row[1], idx, idx ? prev_offset:8);
			data_type.fields.push_back(f);
			if (idx++ > 0)
			  prev_offset += type_size[f.type];
		}
		cout << data_type << endl;
	}

	_conns.push(conn);
	return true;
}

void DataMgr::release()
{
	for (auto it:_data_types)
	{
		if (it.second)
		  delete it.second;
	}
}

bool DataMgr::get(Data& data)
{
	cout << "DataMgr::get" << endl;
	if (data.id() == 0) 
	{
		cout << "invalid data id" << endl;
		return false;
	}

	auto it = _data_types.find(data.data_name());
	if (it == _data_types.end())
	{
		cout << "unknow type:" << data.data_name() << endl;
		return false;
	}

	DBConn conn = _conns.pop();
	if (conn == NULL) return false;

	DataType& data_type = *it->second;
	stringstream sql;
	sql << "select * from " << data.data_name() << " where id=" << data.id();
	cout << "sql:" << sql.str() << endl;

	int ret = mysql_query(conn, sql.str().c_str());
	_conns.push(conn);
	if (ret != 0)
	{
		MYSQL_ERR();
		return false;
	}

	MYSQL_RES*   res;
	MYSQL_ROW    row;
	res = mysql_store_result(conn);
	if (NULL == res)
	{
		MYSQL_ERR();
		return false;
	}

	row = mysql_fetch_row(res);
	if (NULL == row || NULL == row[0])
	{
		MYSQL_ERR();
		return false;
	}

	cout << "DataMgr::get4" << endl;
	for (auto f:data_type.fields)
	{
		cout << f.name << ":" << row[f.idx] << endl;
		set_db_value(row[f.idx], f.name, f.type, (char*)&data + f.offset);
	}

	return true;
}

bool DataMgr::add(Data& data)
{
	cout << "DataMgr::add" << endl;//data << endl;
	auto it = _data_types.find(data.data_name());
	if (it == _data_types.end())
	{
		cout << "unknow type:" << data.data_name() << endl;
		return false;
	}

	DataType& data_type = *it->second;
	stringstream sql;
	bool first = true;
	if (data.id())
	{
		stringstream values;
		for (int i = 0; i < data_type.fields.size(); i++)
		{
			if (!data.get_field(i)) continue;
			auto f = data_type.fields[i];
			if (f.name == "id") continue;

			first ? first = false:values << ",";
			values << f.name << "=";
			append(values, f.type, (char*)(&data) + f.offset);
		}
		sql << "update " << data.data_name() << " set " << values.str() << " where id=" << data.id();
	}
	else
	{
		stringstream fields, values;
		for (auto f:data_type.fields)
		{
			//cout << f << endl;
			if (f.name == "id") continue;
			if (first)
			{
				first = false;
				fields << f.name;
			}
			else
			{
				fields << "," << f.name;
				values << ",";
			}
			append(values, f.type, (char*)(&data) + f.offset); 
		}
		sql << "insert into " << data.data_name() << "(" << fields.str() << ")values(" << values.str() << ")";
	}

	cout << "sql:" << sql.str() << endl;
	DBConn conn = _conns.pop();
	if (conn != NULL)
	{
		cout << " sql:" << sql.str() << endl;
		int ret = mysql_query(conn, sql.str().c_str());
		_conns.push(conn);
		if (ret != 0)
		{
			MYSQL_ERR();
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}

}

bool DataMgr::del(const Data& data)
{
	return true;
}

bool DataMgr::update(Data& data)
{
	return true;
}


bool DataMgr::from_json(Data& data, const string& json_data)
{
	cout << "DataMgr::from_json" << endl;
	value json;
	const char* meta_str = json_data.c_str();
	if (json.load(meta_str, meta_str + json_data.length(), false, nullptr))
	{
		auto it = _data_types.find(data.data_name());
		if (it == _data_types.end())
		{
			cout << "unknow type:" << data.data_name() << endl;
			return false;
		}

		DataType& data_type = *it->second;
		for (auto f:data_type.fields)
		{
			if (get_json_value(json, f.name, f.type, (char*)&data + f.offset))
			{
				cout << "parse:" << f.name << endl;
				data.set_field(f.idx);
			}
		}

		return true;
	}
	
	cout << "invalid json:" << json_data << endl;
	return false;
}



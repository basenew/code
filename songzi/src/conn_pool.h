#pragma once
#include <iostream>
#include <list>
#include <mutex>
#include <mysql/mysql.h>

#define MYSQL_ERR() cout << "errno:" << mysql_errno((MYSQL*)conn) << " errmsg:" << mysql_error((MYSQL*)conn) << endl

using namespace std;

typedef MYSQL* DBConn;

struct Conn
{
	MYSQL mysql;
	int   id;
	bool  active;
};

struct DBCnf
{
	string db;
	string account;
	string passwd;
	string host;
	short  port;
};

class ConnPool
{
public:
	bool init(int conn_cnt, const DBCnf& _cnf);
	DBConn pop();
	void push(DBConn conn);
private:
	list<Conn*> _conns;
	mutex      _mtx;
	int        _conn_cnt;
	DBCnf      _db_cnf;
};


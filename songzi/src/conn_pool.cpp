#include "conn_pool.h"
#include <stdlib.h>
#include <assert.h>

bool ConnPool::init(int conn_cnt, const DBCnf& cnf)
{
	int retry_times = 0;
	for (int i = 0; i < conn_cnt;) 
	{
		Conn* conn = new Conn;
		mysql_init(&conn->mysql);
		if (NULL != mysql_real_connect(&conn->mysql, cnf.host.c_str(), cnf.account.c_str(), cnf.passwd.c_str(), cnf.db.c_str(), 0, NULL, 0))
		{
			retry_times = 0;
			conn->id = i;
			conn->active = true;
			_conns.push_back(conn);
			i++;
		}
		else
		{
			MYSQL_ERR();
			if (++retry_times >= 10) break;
			delete conn;
			//sleep(1);
		}
	}

	cout << "active conn count:" << _conns.size() << endl;
	return true;
}

DBConn ConnPool::pop()
{
	lock_guard<mutex> g(_mtx);
	if (!_conns.empty())
	{
		cout << "pop size:" << _conns.size() << endl;
		Conn* conn = _conns.front();
		_conns.pop_front();
		return (DBConn)conn;
	}
	cout << "conn pool is empty!" << endl;
	return NULL;
}

void ConnPool::push(DBConn conn)
{
	assert(conn != NULL);
	lock_guard<mutex> g(_mtx);
	_conns.push_back((Conn*)conn);
	cout << "push size:" << _conns.size() << endl;
}

#if 0 
int main(int argc, char** argv)
{
	DBCnf cnf;
	cnf.host = "localhost";
	cnf.port = 3306;
	cnf.account = "root";
	cnf.db = "songzi";
	cnf.passwd = "78uijk";
	ConnPool poll;
	poll.init(1, cnf);
}
#endif







#include "/usr/include/mysql/mysql.h"
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{ 
	int count = 100;
	int bat_count = 10;
	if (argc >= 2)
		count = atoi(argv[1]);
	if (argc >= 3)
		bat_count = atoi(argv[2]);

	MYSQL mysql;
	mysql_init(&mysql);
	cout<<"mysql is running"<<endl;
	MYSQL* res = mysql_real_connect(&mysql, "192.168.0.105", "root", "78uijk", "test", 3306, NULL, 0);
	if (!res)
	{
		cout << "connect fail" << endl;
		cout << "err:" << mysql_errno(&mysql) << endl;	
	}
	string sql = "insert into test(name, num) values('hello', 1000001);";
	int t1 = time(NULL);
	
	string sqls;
	for (int i = 0; i < count; i++)
	{
		sqls += sql;
		if (((i + 1) % bat_count) == 0)
		{
			mysql_query(&mysql, sqls.c_str());
			sqls = "";
		}
	}

	int t2 = time(NULL);
	cout << "time:" << t2 - t1 << endl;
	mysql_close(&mysql);
	return 0;
}

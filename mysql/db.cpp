#include "/usr/include/mysql/mysql.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{ 
	MYSQL mysql;
	mysql_init(&mysql);
	cout<<"mysql is running"<<endl;
	MYSQL* res = mysql_real_connect(&mysql, "192.168.0.107", "root", "78uijk", "test", 3306, NULL, 0);
	if (!res)
	{
		cout << "connect fail" << endl;
		cout << "err:" << mysql_errno(&mysql) << endl;	
	}
	string sql = " insert into test(name, num) values('hello', 1000001);";
	mysql_query(&mysql, sql.c_str());
	mysql_close(&mysql);
	return 0;
}

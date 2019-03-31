#include "/usr/include/mysql/mysql.h"
#include <unistd.h>
#include <stdio.h>

#include<iostream>
#include<sstream>
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

	int idx = 0;
	if (argc >= 4)
	{
		int proc_count = atoi(argv[3]) - 1;
		for (int i = 0; i < proc_count; i++)
			if (0 == fork())
			{
				idx = i+1;
				break;
			}
	}

	MYSQL mysql;
	mysql_init(&mysql);
	cout<<"mysql is running"<<endl;
	//MYSQL* res = mysql_real_connect(&mysql, "192.168.0.105", "root", "78uijk", "test", 3306, NULL, 0);
	//MYSQL* res = mysql_real_connect(&mysql, "192.168.0.105", "root", "78uijk", "test", 3306, NULL, CLIENT_MULTI_STATEMENTS);
	//MYSQL* res = mysql_real_connect(&mysql, "192.168.0.105", "root", "78uijk", "test", 3306, NULL, CLIENT_MULTI_RESULTS);
	MYSQL* res = mysql_real_connect(&mysql, "127.0.0.1", "root", "78uijk", "test", 3306, NULL, CLIENT_MULTI_RESULTS);
	if (!res)
	{
		cout << "err:" << mysql_errno(&mysql) << endl;	
		getchar();
		exit(1);
	}
	string sql = "insert into test(name, num) values('hello', 1000001)";
	/*stringstream ssql;
	ssql << "insert into test";
	ssql << idx;
	ssql << "(name, num) values('hello', 1000001)";
	string sql;
	ssql >> sql;*/
	cout << sql << endl;
	getchar();
	string value(",('hellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhellhelloooooooooooooooooooooooooooooooooooooooooohello', 1000001)");
	int t1 = time(NULL);
	
	int ret;
	string sqls = sql;
	for (int i = 0; i < count; i++)
	{
		sqls += value;
		//cout << sqls << endl;
		//cout << "------------------------------------------" << endl;
		if (((i + 1) % bat_count) == 0)
		{
			ret = mysql_query(&mysql, sqls.c_str());
			sqls = sql;
			if (ret != 0)
				cout << i << " err:" << mysql_error(&mysql) << endl;
		}
	}

	int t2 = time(NULL);
	cout << "time:" << t2 - t1 << endl;
	mysql_close(&mysql);
	return 0;
}

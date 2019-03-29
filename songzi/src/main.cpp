#include "data_mgr.h"
#include "user.h"

int main(int argc, char** argv)
{
	DBCnf cnf;
	cnf.host = "localhost";
	cnf.port = 3306;
	cnf.account = "root";
	cnf.db = "songzi";
	cnf.passwd = "78uijk";
	data_mgr.init(cnf, 1);

	User user;
	user.name("basenew");
	user.phone("18000013800");
	user.idcard("4418000013800");
	user.sex(1);
	user.age(36);
	string user_json;
	data_mgr.to_json(user, user_json);
	cout << "user1:" << user_json << endl;
	data_mgr.add(user);

	User user2;
	data_mgr.from_json(user2, user_json);
	data_mgr.to_json(user2, user_json);
	cout << "user2:" << user_json << endl;

	return 0;
}


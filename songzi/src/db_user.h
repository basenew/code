#pragma once
#include "user.h"

class DBUser
{
public:
	DBUser(User& user);
	~DBUser();
	bool insert();
	bool update();

private:
	User _user;
};

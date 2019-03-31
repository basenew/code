<<<<<<< HEAD
#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <stdlib.h>


class user: public cppcms::application {
public:
    user(cppcms::service &srv) :
        cppcms::application(srv) 
    {
        dispatcher().assign("/login-verify-code",&user::login_verify_code,this);
        mapper().assign("login-verify-code","/login-verify-code");
        
        dispatcher().assign("/get-verify-code",&user::get_verify_code,this);
        mapper().assign("get-verify-code","/get-verify-code");

        dispatcher().assign("/logout",&user::logout,this);
        mapper().assign("logout", "/logout");

        dispatcher().assign("/update",&user::update,this);
        mapper().assign("update", "/update");

        dispatcher().assign("/get",&user::get,this);
        mapper().assign("get", "/get");

        dispatcher().assign("",&user::hello,this);
        mapper().assign("");

        mapper().root("/user");
    }
    void hello(){response().out() << "hello";};
    void login_verify_code();
    void get_verify_code();
    void update();
    void logout();
    void get();
};

=======
#pragma once
#include "data.h"

#include <iostream>
#include <cppcms/json.h>

using namespace std;
using namespace cppcms::json;


class User:public Data
{
public:
	User():Data("user"), _sex(male){};
	User(const string& json):Data("user"){from_json(json);};
	inline const VarStr& name(){return _name;};
	inline const VarStr& phone(){return _phone;};
	inline const VarStr& idcard(){return _idcard;};
	inline unsigned char age(){return _age;};
	inline unsigned char sex(){return _sex;};
	inline void name(const string& name){_name = name;};
	inline void phone(const string& phone){_phone = phone;};
	inline void idcard(const string& idcard){_idcard = idcard;};
	inline void age(unsigned char age){_age = age;};
	inline void sex(unsigned char sex){_sex = sex;};

	bool from_json(const string& json);
	string to_json();//mybe use move
	inline ostream& operator<<(ostream& o)
	{
		o << "name:" << _name.data << " phone:" << _phone.data << " idcard:" << _idcard.data << " age:" << _age << " sex:" << _sex;
		return o;
	};
private:
	VarStr _name;
	VarStr _phone;
	VarStr _idcard;
	unsigned char _age;
	unsigned char _sex;
};

bool User::from_json(const string& user_json_str)
{
	value user_json;
	const char* meta_str = user_json_str.c_str();
	if (user_json.load(meta_str, meta_str + user_json_str.length(), true, nullptr))
	{
		_name = user_json["name"].str();
		_phone = user_json["phone"].str();
		_idcard = user_json["idcard"].str();
		_age = user_json["age"].number();
		_sex = user_json["sex"].number();
		return true;
	}
	cout << "err json:" << user_json_str << endl;
	return false;
}

string User::to_json()
{
	value json;
	json["name"] = _name.str();	
	json["phone"] = _phone.str();	
	json["idcard"] = _idcard.str();	
	json["age"] = _age;	
	json["sex"] = _sex;	
	return json.save();
}
>>>>>>> d43e41208ff4872ba79123b37b6d25e93b255a5f

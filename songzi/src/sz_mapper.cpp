#include "sz_mapper.h"
#include "user.h"
#include "prescription.h"
#include "data_mgr.h"

#include <time.h>
#include <cppcms/http_request.h>

#include <iostream>

using namespace std;


void SZMapper::login_verify_code()
{
    response().out() << "login_verify_code rsp";
}

void SZMapper::get_verify_code()
{
    response().out() << "get_verify_code rsp";
}

void SZMapper::logout()
{
    response().out() << "logout rsp";
}

void SZMapper::update_user()
{
    pair<void *,size_t> json_pair = request().raw_post_data();
    cout << "update len:" << json_pair.second << " json:" << (char*)json_pair.first << endl;
    if (json_pair.second)
    {
		string user_json((char*)json_pair.first);
		User user;
		data_mgr.from_json(user, user_json);
		if (data_mgr.add(user))
		{
			response().out() << "update rsp\r\n";
		}
		else
		{
			response().out() << "add user fail\r\n";
		}
	}
	else
		response().out() << "update user json data is empty";
}

void SZMapper::get_user()
{
    pair<void *,size_t> json_pair = request().raw_post_data();
    cout << "get len:" << json_pair.second << " json:" << (char*)json_pair.first << endl;
    if (json_pair.second)
    {
		string user_json((char*)json_pair.first);
		User user;
		data_mgr.from_json(user, user_json);
		if (data_mgr.get(user))
		{
			data_mgr.to_json(user, user_json);
			response().out() << user_json;
		}
		else
		{
			response().out() << "add user fail\r\n";
		}
	}
	else
		response().out() << "get user json data is empty";
}

void SZMapper::update_prescription()
{
    pair<void *,size_t> json_pair = request().raw_post_data();
    cout << "update len:" << json_pair.second << " json:" << (char*)json_pair.first << endl;
    if (json_pair.second)
    {
		string json_str((char*)json_pair.first);
		Prescription &data = *(new Prescription());
		data_mgr.from_json(data, json_str);
		data.from_time(time(NULL));
		if (data_mgr.add(data))
		{
			response().out() << "update rsp\r\n";
		}
		else
		{
			response().out() << "update fail\r\n";
		}
	}
	else
		response().out() << "update json data is empty";
}

void SZMapper::get_prescription()
{
    pair<void *,size_t> json_pair = request().raw_post_data();
    cout << "get len:" << json_pair.second << " json:" << (char*)json_pair.first << endl;
    if (json_pair.second)
    {
		string json_str((char*)json_pair.first);
		Prescription data;
		data_mgr.from_json(data, json_str);
		if (data_mgr.get(data))
		{
			data_mgr.to_json(data, json_str);
			response().out() << json_str;
		}
		else
		{
			response().out() << "get fail\r\n";
		}
	}
	else
		response().out() << "get json data is empty";
}

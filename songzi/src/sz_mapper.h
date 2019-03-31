#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <stdlib.h>
#include "mp_user.h"
#include "mp_prescription.h"


class SZMapper: public cppcms::application {
public:
	SZMapper(cppcms::service &srv) :
			cppcms::application(srv) 
	{
		dispatcher().assign("/user/login-verify-code",&SZMapper::login_verify_code, this);
		mapper().assign("login-verify-code","/user/login-verify-code");
		dispatcher().assign("/user/get-verify-code",&SZMapper::get_verify_code, this);
		mapper().assign("get-verify-code","/user/get-verify-code");
		dispatcher().assign("/user/logout",&SZMapper::logout, this);
		mapper().assign("logout", "/user/logout");
		dispatcher().assign("/user/update",&SZMapper::update_user, this);
		mapper().assign("user_update", "/user/update");
		dispatcher().assign("/user/get",&SZMapper::get_user, this);
		mapper().assign("user_get", "/user/get");

		dispatcher().assign("/prescription/update",&SZMapper::update_prescription, this);
		mapper().assign("prescription_update", "/prescription/update");
		dispatcher().assign("/prescription/get",&SZMapper::get_prescription, this);
		mapper().assign("prescription_get", "/prescription/get");
		mapper().root("/");
	}

	void login_verify_code();
	void get_verify_code();
	void logout();
	void update_user();
	void get_user();
	void update_prescription();
	void get_prescription();
};


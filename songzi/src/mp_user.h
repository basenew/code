#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <stdlib.h>


class UserMapper: public cppcms::application {
public:
    UserMapper(cppcms::service &srv) :
        cppcms::application(srv) 
    {
        dispatcher().assign("/login-verify-code",&UserMapper::login_verify_code,this);
        mapper().assign("login-verify-code","/login-verify-code");
        
        dispatcher().assign("/get-verify-code",&UserMapper::get_verify_code,this);
        mapper().assign("get-verify-code","/get-verify-code");

        dispatcher().assign("/logout",&UserMapper::logout,this);
        mapper().assign("logout", "/logout");

        dispatcher().assign("/update",&UserMapper::update,this);
        mapper().assign("update", "/update");

        dispatcher().assign("/get",&UserMapper::get,this);
        mapper().assign("get", "/get");

        dispatcher().assign("",&UserMapper::hello,this);
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


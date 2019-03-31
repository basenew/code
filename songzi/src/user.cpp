#include "user.h"


void user::login_verify_code()
{
    response().out() << "login_verify_code rsp";
}

void user::get_verify_code()
{
    response().out() << "get_verify_code rsp";
}

void user::logout()
{
    response().out() << "logout rsp";
}

void user::update()
{
    response().out() << "update rsp";
}

void user::get()
{
    response().out() << "get rsp";
}

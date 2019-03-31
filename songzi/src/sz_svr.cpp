<<<<<<< HEAD
#include "user.h"
=======
#include "sz_mapper.h"
#include "data_mgr.h"
>>>>>>> d43e41208ff4872ba79123b37b6d25e93b255a5f
#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <stdlib.h>



int main(int argc,char ** argv)
{
<<<<<<< HEAD
    try {
        cppcms::service app(argc,argv);
        app.applications_pool().mount(cppcms::applications_factory<user>());
=======
    DBCnf cnf;
    cnf.host = "localhost";
    cnf.port = 3306;
    cnf.account = "root";
    cnf.db = "songzi";
    cnf.passwd = "78uijk";
    if (!data_mgr.init(cnf, 1))
      return -1;

    try {
        cppcms::service app(argc,argv);
        app.applications_pool().mount(cppcms::applications_factory<SZMapper>());
>>>>>>> d43e41208ff4872ba79123b37b6d25e93b255a5f
        app.run();
    }
    catch(std::exception const &e) {
        std::cerr<<e.what()<<std::endl;
    }
}
<<<<<<< HEAD
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
=======
>>>>>>> d43e41208ff4872ba79123b37b6d25e93b255a5f

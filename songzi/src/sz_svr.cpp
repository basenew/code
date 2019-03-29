#include "sz_mapper.h"
#include "data_mgr.h"
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
        app.run();
    }
    catch(std::exception const &e) {
        std::cerr<<e.what()<<std::endl;
    }
}

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <stdlib.h>


class PrescriptionMapper: public cppcms::application {
public:
    PrescriptionMapper(cppcms::service &srv) :
        cppcms::application(srv) 
    {
        dispatcher().assign("/update",&PrescriptionMapper::update,this);
        mapper().assign("update", "/update");

        dispatcher().assign("/get",&PrescriptionMapper::get,this);
        mapper().assign("get", "/get");

        mapper().root("/prescription");
    }
    void update();
    void get();
	void test()
	{
			response().out() << "test\r\n";
	};
};


#include <cppcms/application.h> 
#include <cppcms/applications_pool.h> 
#include <cppcms/http_response.h> 
#include <cppcms/service.h> 
#include <iostream> 
#include <chrono> 
#include <ctime> 
#include <cppcms/json.h> 

using namespace cppcms; 
using namespace std; 


class hello : public cppcms::application {   
	public:   
		hello(cppcms::service &srv) :   
			cppcms::application(srv)   
	{   
	}   
		virtual void main(std::string url);   
};  

void hello::main(std::string /*url*/)   
{  

	http::request& req = request();
	std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	response().out() << "hello zouyang!!!" << std::ctime(&now_time);
	/*response().out() <<  
	  "<html>\n"  
	  "<body>\n"  
	  "  <h1>Hello World</h1>\n"  
	  "</body>\n"  
	  "</html>\n";*/  
}

void test_json()
{
	char const *jsn_str=
		"{ \"t\" : [{},{},{},{ \"x\":1},[]],\"x\" : { \"o\" : { \"test\" : [ 10,20,true ], \"post\" : 13.01 }, \"yes\" : \"\\u05d0א\" }}";
	json::value v;
	v["name"] = "basenew";
	v["age"] = 33;
	cout << "json:" << v;

	json::value v2;
	if (v2.load(jsn_str, jsn_str + strlen(jsn_str), true))
	{
		cout << "json2:" << v2;
	}       
	else
	{
		cout << "convert json fail" << endl;
	}
}

int main(int argc,char ** argv)  
{  
	try {  
//		test_json();
		cppcms::service srv(argc,argv);  
		srv.applications_pool().mount(  
				cppcms::applications_factory<hello>());
		srv.run();  
	}  
	catch(std::exception const &e) {  
		std::cerr << e.what() << std::endl;  
	}
}

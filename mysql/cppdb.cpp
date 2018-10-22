#include <iostream>
using namespace std;
#include <cppdb/frontend.h>

int main(int argc,char* argv[]){
        try{
                string connection_string("mysql:host=192.168.0.107;database=songzi;user=root;password=78uijk;set_charset_name=utf8");
                cppdb::session session(connection_string);
                string sql="select * from patient";
                cppdb::result res = session<<sql;
                while(res.next()){
                        cout<<res.get<string>("address")<<endl;
                }
        }catch(std::exception const& ex){
                cout<<ex.what()<<endl;
        }catch(...){
                cout<<"Unknown exception"<<endl;
        }
}

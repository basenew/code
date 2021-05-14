g++ -fPIC -shared -o libcatstr.so catstr_api.cpp catstr.cpp 
g++ -o test main.cpp -lcatstr -L. -ldl
./test

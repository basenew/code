#include <iostream>
#include <vector>

using namespace std;

class ListNum{
public:
	ListNum(const string& snum):lnum_(snum){
	};

	ListNum(const ListNum<T>& lnum){
		lnum_ = lnum.lnum_;
	};


	int operator[](int i){return lnum_[i];};
	int& operator[](int i){return lnum_[i];};

	ostream& operator<<(ostream& o){
		return o << num_; 
	};

	ListNum operator+(const ListNum& r){
		string sum;
		int len = lnum_.length();
		if(len < r.lnum_.length())
			len = r.lnum_.length();
		for(int i = len - 1; i >= 0; --i){
		}
	};
	ListNum& operator+(const ListNum& r){
	};

	void to_list_num(){
		
	};
private:
	string lnum_;
};

int main(int argc, char** argv){
	return 0;
}



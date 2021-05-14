#pragma once
#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& a){
	for(auto v:a){
		cout << v <<" ";
	}
	cout << endl;
}

void merge_order_array(const vector<int>& a1, const vector<int>& a2, vector<int>& m){
	int k = 0, i = 0, j = 0;
	while(i < a1.size() && j < a2.size())
		m.push_back((a1[i]<=a2[j]) ? a1[i++]:a2[j++]);
	if(i >= a1.size()){
		while(j < a2.size())
			m.push_back(a2[j++]);
	}else{
		while(i < a1.size())
			m.push_back(a1[i++]);
	}
}

void test_merge_order_array(){
	vector<int> a1{1,3,7,8,11,18,19,33};
	vector<int> a2{0,4,5,6, 9,11,13,19,22,25};
	vector<int> m;
	merge_order_array(a1, a2, m);
	print(m);
}

int main(){
    test_merge_order_array();
	return 0;
}



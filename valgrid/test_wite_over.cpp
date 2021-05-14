int main(int argc, char** argv){
	char* arr = new char[3];
    int* p = (int*)arr;	
	*p = 0xffffffff;
	//delete[] arr;
	return 0;
}


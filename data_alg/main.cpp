#include "bintree.h"

template<class T>
void print(const T &t)
{
	cout << t <<" ";
}

int main(int argc, char* argv[])
{
	int invalid = 0;
	int arr[]{1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};
	BinTree<int> t(arr, 15, invalid);
	cout << "h:" << t.high() << endl;
	t.preorder(print);
	cout << endl;
	t.inorder(print);
	cout << endl;
	t.postorder(print);
	cout << endl;
	return 0;
}

#include <iostream>
#include <time.h>

using namespace std;

const int count_per_line = 20;
int arr_size = 1000000;
int arr_count = 10;
const int random_num = 1000000;

#define T1 \
	long t1 = time(NULL);
#define T2(name) \
	cout << name <<" t:" << time(NULL) - t1 << endl; 



void bubble(int *a, int len)
{
	//long t1 = time(NULL);
	T1
		for(int i = 1; i < len; i++)
			for (int j = 0; j < len - i; j++)
			{
				if (a[j] > a[j+1])
				{
					swap(a[j], a[j+1]);
					//int tmp = a[j];
					//a[j] = a[j+1];
					//a[j+1] = tmp;
				}
			}	
	T2("bubble")
		//cout << "t:" << time(NULL) - t1 << endl; 
}

void print(int *a, int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
		if (i && (i % count_per_line == 0)) cout << endl;

	}
	cout << endl;
}

void select(int *a, int len)
{
	T1
		for (int i = len - 1; i > 0; i--)
		{
			int max = i;
			for (int j = 0; j <= i; j++)
			{
				if (a[j] > a[max])
					max = j;
			}
			swap(a[i], a[max]);
		}
	T2("select")	
}


void insert(int *a, int len)
{
	//print(a, len);
	T1
		for(int i = 1; i < len; i++)
		{
			int v = a[i];
			for (int j = 0; j < i; j++)
			{
				if (v < a[j])
				{
					for (int k = i; k > j; k--)
						a[k] = a[k-1];
					a[j] = v;
				}
			}
		}
	T2("insert")
		//print(a, len);
}

void quick(int *a, int len)
{
	if (len < 2) return;

	int mid = a[len/2];
	int i = 0, j = len - 1;
	do
	{
		while (i < len && a[i] < mid) i++;
		while (j >= 0 && a[j] > mid) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;	
		}
	}while(i <= j);
	if (i < len - 1)
		quick(a, i + 1);
	if (j > 0)	
		quick(a + i + 1, len - i - 1);

}

void run(int* pData,int left,int right) 
{ 
	int i,j; 
	int middle,iTemp; 
	i = left; 
	j = right; 
	middle = pData[left]; 
	do{ 
		while((pData[i]<middle) && (i<right))//从左扫描大于中值的数 
		i++;
		while((pData[j]>middle) && (j>left))//从右扫描大于中值的数 
		j--; 
		if(i<=j)//找到了一对值 
		{ 
			
			iTemp = pData[i]; 
			pData[i] = pData[j]; 
			pData[j] = iTemp; 
			i++; 
			j--; 
		} 
	}while(i<=j);//如果两边扫描的下标交错,就停止（完成一次） 
	
	if(left<j) 
		run(pData,left,j); 
	
	if(right>i) 
		run(pData,i,right); 
}

void QuickSort(int* pData,int Count) 
{ 
	run(pData,0,Count-1); 
}

int main(int argc, char* argv[])
{
	//	int rd = random(1000);

	//	int a[20] = {11, 12,5, 6, 3, 100, 1000, 99, 88,22, 1, 95, 2, 0, 7, 33, 44,10, 31, 20};
	if (argc > 1)
		arr_size = atoi(argv[1]);

	//int a[arr_count][arr_size];
	int **a = new int*[arr_count];
	for (int i = 0; i < arr_count; i++)
	{
		a[i] = new int[arr_size];
	}

	for (int i = 0; i < arr_size; i++)
	{	
		int v = random() % random_num;
		for (int j = 0; j < arr_count; j++)
			a[j][i] = v;
	}
	//print(a, arr_size);
	//bubble(a[0], arr_size);	
	//select(a[1], arr_size);	
	//insert(a[2], arr_size);	
	//print(a[3], arr_size);
	T1
		QuickSort(a[3], arr_size);	
	T2("quick")
		delete []a;
	//print(a[3], arr_size);
	//print(a, arr_size);
	return 0;
}

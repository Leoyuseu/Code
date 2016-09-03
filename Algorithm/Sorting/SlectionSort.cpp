#include <iostream>  
using namespace std;

template <class T>
void SelectionSort(T a[], int n)
{//及时终止的选择排序
	bool sorted = false;
	for (int size = n; !sorted && (size>1); size--)
	{
		int pos = 0;
		sorted = true;
		//找最大元素
		for (int i = 1; i<size; i++)
		if (a[pos] <= a[i])
			pos = i;//如果已经按序排列，那么就不会有else的机会，sorted也就一直为true，最红将终止外部for循环。
		else
			sorted = false;//非未按序排列，表示需要外部for循环
		Swap(a[pos], a[size - 1]);
		show(a, n);
	}
}

template<class T>
void Swap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}

template <class T>
void show(T arr, int n){
	for (int i = 0; i<n - 1; i++){
		cout << arr[i] << ",";
	}
	cout << arr[n - 1] << endl;
}

void main()
{
	int inputNumber[] = { 2, 7, 5, 9, 1, 4, 6, 3, 8 };
	int count = 9;
	cout << "原始数组：" << endl;
	show(inputNumber, count);
	cout << "排序过程：" << endl;
	SelectionSort(inputNumber, count);
	cout << "排序结果：" << endl;
	show(inputNumber, count);
}
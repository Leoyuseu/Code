#include <iostream>
using namespace std;

template <class T>
void  BubbleSort(T& nData, int len)
{
	//bool isOk = false;   //用于排序好了提前结束	
	for (int i = 0; i<len - 1; ++i)
	{
		//isOk = true;
         for (int j = len - 1; j > i; --j)
		 {
            if (nData[j]<nData[j - 1])
			{
                int temp = nData[j];
                nData[j] = nData[j - 1];
                nData[j - 1] = temp;
			//	isOk = false;
                show(nData, len);
			}
		}
	}
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
	int inputNumber[] =  { 2, 7, 5, 9, 1, 4, 6, 3, 8 };
	int count = 9;


    cout << "原始数组：" << endl;
    show(inputNumber, count);
    cout << "排序过程：" << endl;
	BubbleSort(inputNumber, count);
    cout << "排序结果：" << endl;
    show(inputNumber, count);
 }


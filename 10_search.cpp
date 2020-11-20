#include <iostream>
using namespace std;

//顺序查找就是从头到尾逐个比较

//二分查找
int binarySearch(int A[],int len,int key)
{
	int low = 0,high = len-1;
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(A[mid] == key)
			return A[mid];
		else if(A[mid] > key)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;    //没找到
}
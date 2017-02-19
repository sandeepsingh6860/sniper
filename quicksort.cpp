#include<bits/stdc++.h>
using namespace std;
int findpivot(int arr[],int low,int high)
{
	 int pindex=low-1;
	 int pivot=arr[high];
	 for(int i=0;i<high;i++)
	 {
	 	 if(arr[i]<=pivot)
	 	 {
	 	   pindex++;
           swap(arr[pindex],arr[i]);
	 	 }
	 }
	 swap(arr[pindex+1],arr[high]);
	 return(pindex+1);
}
void quicksort1(int arr[],int low,int high)
{
	if(high>low)
	{
		int pivot=findpivot(arr,low,high);
		quicksort1(arr,low,pivot-1);
		quicksort1(arr,pivot+1,high);
	}
}
void print(int arr[],int length)
{
	//cout<<arr[4];
	for(int i=0;i<length;i++)
		cout<<arr[i]<<" ";
	//cout<<"gh";
}
int main()
{
	int arr[]={32,2,1,44,22,13,2342};
	int length=sizeof(arr)/sizeof(arr[0]);
	int low=0;
	int high=length-1;
	quicksort1(arr,low,high);
	print(arr,length);
	return 0;
}
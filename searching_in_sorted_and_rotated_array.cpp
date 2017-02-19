#include<bits/stdc++.h>
using namespace std;
int find_pivot(int arr[],int start,int end,int key)
{
    int mid=(start+end)/2;
    if(arr[mid]==key)
    	return mid;
    if(mid<end&&arr[mid]>arr[mid+1])
    	return mid;
    if(mid>start&&arr[mid]<arr[mid-1])
    	return mid-1;
    if(arr[start]>arr[mid])
    	return find_pivot(arr,start,mid-1,key);
    else
         return find_pivot(arr,mid+1,end,key);
}
int binary_Search(int arr[],int start,int end,int key)
{
	 if(start<end)
	 {
	 	 int mid=(start+end)/2;
	 	 if(arr[mid]==key)
	 	 	return mid;
	 	 if(arr[mid]>key)
	 	 	 return binary_Search(arr,start,mid-1,key);
	 	 else
	 	 	  return binary_Search(arr,mid+1,end,key);
	 }
	 return -1;
}
int search(int arr[],int size,int key)
{
	 int pivot=find_pivot(arr,0,size-1,key);
	 if(pivot==-1)
	 	return binary_Search(arr,0,size-1,key);
	 if(arr[pivot]==key)
	 	 return pivot;
     else if(arr[0]>key)
     	 return binary_Search(arr,pivot+1,size-1,key);
     else
     	 return binary_Search(arr,0,pivot-1,key);
}
int main()
{
	 int arr[]={5,6,7,8,9,10,1,2,3};
	 int size=sizeof(arr)/sizeof(arr[0]);
	 int key=2;
	 cout<<search(arr,size,key);
	 return 0;
}
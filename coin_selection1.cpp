#include<bits/stdc++.h>
using namespace std;
#define INF 10000
void print(int arr1[])
{
	 for(int i=0;i<14;i++)
	 {
	 	 cout<<arr1[i]<<" ";
	 }
}
void coin_selection(int arr[],int size,int arr1[],int arr2[])
{
	// cout<<size;
	 for(int i=0;i<size;i++)
	 {
	 	 for(int j=1;j<14;j++)
	 	 {
	 	 	 if(arr[i]<=j)
               {
               	   int temp=arr1[j];
               	   arr1[j]=min(arr1[j],1+arr1[j-arr[i]]);
               	   if(arr1[j]!=temp)
               	      arr2[j]=i;
               }
	 	 }
	 }
	 print(arr1);
	 cout<<"\n";
	 print(arr2);
}
int main()
{
	 int arr[]={7,2,3,6};
	 int total=13;
	 int arr1[14];
	 int arr2[14];
	 for(int i=1;i<14;i++)
	 {
	 	 arr1[i]=INF;
	 }
	 for(int i=0;i<14;i++)
	 	 arr2[i]=-1;
	  arr1[0]=0;
      
      int size=sizeof(arr)/sizeof(arr[0]);
     // cout<<size;
      coin_selection(arr,size,arr1,arr2);
	  return 0;
}
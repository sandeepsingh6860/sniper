#include<bits/stdc++.h>
using namespace std;
void counting_sort(int arr[],int length,int exp)
{
	int count[10]={0};
	int output[40];
    for(int i=0;i<length;i++)
    {
    	 count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++)
    {
    	 count[i]+=count[i-1];
    }
    for(int i=length-1;i>=0;i--)
    {
    	 output[count[(arr[i]/exp)%10]-1]=arr[i];
    	 count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<length;i++)
    {
    	 arr[i]=output[i];
    }
}
int getmax(int arr[],int length)
{
	int max=arr[0];
	for(int i=1;i<length;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
void radix_sort(int arr[],int length)
{
   int max=getmax(arr,length);
   for(int exp=1;max/exp>0;exp*=10)
   {
   	 counting_sort(arr,length,exp);
   }
}
void print(int arr[],int length)
{
	 for(int i=0;i<length;i++)
	 	cout<<arr[i]<<" ";
}
int main()
{
	int arr[]={2423,4,23,1,34,52};
	int length=sizeof(arr)/sizeof(arr[0]);
	radix_sort(arr,length);
	print(arr,length);
	return 0;
}
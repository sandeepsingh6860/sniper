#include<bits/stdc++.h>
using namespace std;
void cycle_Sort(int arr[],int size)
{
	 int cycle=0;
	 int pos;
	 int write=0;
	for(cycle=0;cycle<=size-2;cycle++)
    {
    	int item=arr[cycle];
    	pos=cycle;
	 for(int i=cycle+1;i<size;i++)
	 {
         if(arr[i]<item)
         	pos++;
	 }
	 if(pos==cycle)
	 	continue;
	 if(arr[pos]==item)
	 	pos++;
	 if(pos!=cycle)
	 {
	 	 swap(item,arr[pos]);
	 	 write++;
	 }
	 while(pos!=cycle)
	 {
       pos=cycle;
       for(int i=cycle+1;i<size;i++)
        {
        	 if(arr[i]<item)
        	 	 pos++;
        }
       if(item!=arr[pos])
       	 {
       	 	 swap(item,arr[pos]);
       	 	 write++;
       	 }
       	 if(item==arr[pos])
       	 	pos++;
	 }
}
cout<<write<<"\n";
}
void display(int arr[],int length)
{
	 for(int i=0;i<length;i++)
	 	cout<<arr[i]<<" ";
}
int main()
{
	int arr[]={10,4,5,2};
	int length=sizeof(arr)/sizeof(arr[0]);
	cycle_Sort(arr,length);
	display(arr,length);
	return 0;
}
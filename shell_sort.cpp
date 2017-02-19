#include<iostream>
using namespace std;
void shellsort(int arr[],int length)
{
   for(int gap=length/2;gap>0;gap/=2)
   {
    
        for(int i=gap;i<length;i++)
        {
           int temp=arr[i];
           int j;
           for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
           {
               arr[j]=arr[j-gap];
           }
          arr[j]=temp;
        }
   }
}
void print(int arr[],int length)
{
    for(int i=0;i<length;i++)
    {
       cout<<arr[i]<<" ";
    }
}
int main()
{
   int arr[]={1,4,1,2,7,5,2};
   int length=sizeof(arr)/sizeof(arr[0]);
   shellsort(arr,length);
   print(arr,length);
   return 0;
}
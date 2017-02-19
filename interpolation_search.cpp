#include<bits/stdc++.h>
using namespace std;
int interpolation_search(int arr[],int length,int key)
{
     int low=0;
     int high=length-1;
     while(low<=high&&arr[low]<=key&&key<=arr[high])
     {
         int pos=((double)(high-low)/(arr[high]-arr[low]))*(key-arr[low])+low;
         if(arr[pos]==key)
             return pos;
         else if(arr[pos]<key)
             {
                low=pos+1;
             }
         else
              high=pos-1;
     }
    return -1;
}
int main()
{
     int arr[]={10,12,13,16,18,19,20,21,22,23,24,33,35,42,47};
     int length=sizeof(arr)/sizeof(arr[0]);
     int find=10;
     cout<<interpolation_search(arr,length,find);
}
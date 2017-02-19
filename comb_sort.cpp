#include<iostream>
using namespace std;
void Comb_Sort(int arr[],int number)
{
    int gap=number/1.3;
    int temp;
    for(int i=gap;i>0;i/=1.3)
    {
       for(int j=i;j<number;j++)
       {
          int key=arr[j];
          if(arr[j-i]>key)
          {
              temp=arr[j-i];
              arr[j-i]=arr[j];
              arr[j]=temp;
          }
       }
    } 
}
void print(int arr[],int number)
{
	 for(int i=0;i<number;i++)
	 	 cout<<arr[i]<<" ";
}
int main()
{
	int number;
    cout<<"ENTER THE TOTAL NO";
    cin>>number;
    int *arr=new int[number];
    cout<<"ENTER THE ELEMENTS";
    for(int i=0;i<number;i++)
     cin>>arr[i];
    Comb_Sort(arr,number);
    print(arr,number);
	return 0;
}
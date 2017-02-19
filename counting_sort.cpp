#include<iostream>
using namespace std;
void print(int arr[],int number)
{
	for(int i=0;i<number;i++)
		cout<<arr[i]<<" ";
}
void Counting_sort(int arr[],int number)
{
	 int count[10]={0};
	 int *output=new int[number];
	 for(int i=0;i<number;i++)
	 	count[arr[i]]++;
	for(int i=1;i<10;i++)
	 	count[i]+=count[i-1];
	 for(int j=0;j<number;j++)
	 {
          output[count[arr[j]]-1]=arr[j];
          count[arr[j]]--;
	 }
	print(output,number);
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
    Counting_sort(arr,number);
   // print(arr,number);
	return 0;
}
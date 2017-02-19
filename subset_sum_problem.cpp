#include<bits/stdc++.h>
using namespace std;
void print(bool matrix[5][12])
{
	for(int i=0;i<5;i++)
	{
		 for(int j=0;j<12;j++)
		 	 cout<<matrix[i][j]<<" ";
		 cout<<"\n";
	}

}
void get_subsets(bool matrix[5][12],int value[],int total)
{
	 for(int i=0;i<5;i++)
	 	matrix[i][0]=true;
	 for(int j=1;j<12;j++)
	 {
	 	 if(value[0]>j||value[0]<j)
           matrix[0][j]=false;
         else
         	 matrix[0][j]=true;
	 }
	 for(int i=1;i<5;i++)
	 {
	 	 for(int j=1;j<12;j++)
	 	 {
	 	 	 if(value[i]>j)
               matrix[i][j]=matrix[i-1][j];
              else
              {
              	 matrix[i][j]=((matrix[i-1][j-value[i]])||(matrix[i-1][j]));
              }
	 	 }
	 }
	 print(matrix);
}
void get_elements(bool matrix[5][12],int arr[])
{
	int a=matrix[4][11];
	int i=4,j=11;
	while(j!=0)
	{
		if(a==matrix[i-1][j])
		{
			i--;
			cout<<arr[i];
		}
		else
		{
			i--;
			j-=arr[i];
		}
	}
}
int main()
{
	int arr[]={2,3,7,8,10};
	int total=11;
	bool arr1[5][12];
    get_subsets(arr1,arr,total);
    get_elements(arr1,arr);
	return 0;
}
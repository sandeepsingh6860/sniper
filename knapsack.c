#include<iostream>
using namespace std;
int matrix[4][8];
void print(int matrix[4][8])
{
	 for(int i=0;i<4;i++)
	 {
	 	 for(int j=0;j<8;j++)
	 	 	cout<<matrix[i][j]<<" ";
	 	cout<<"\n";
	 }
}
void knapsack(int matrix[4][8],int weight[],int value[])
{
	//print(matrix);
	 for(int i=0;i<4;i++)
	 {
	 	for(int j=1;j<=7;j++)
	 	{
	 		 if(weight[i]>j)
	 		 	matrix[i][j]=matrix[i-1][j];
	 		 else
	 		 {
	 		 	 if(i==0)
	 		 	 {
	 		 	 	 matrix[i][j]=value[i];
	 		 	 }
	 		 	 else
	 		 	 matrix[i][j]=max(matrix[i-1][j],value[i]+matrix[i-1][j-weight[i]]);
	 		 }
	 	}
	 }
	print(matrix);
}
void indexes(int matrix[4][8],int weight[])
{
	 int i=3;
	 int j=7;
	 int m=matrix[i][j];
	 while(m!=0)
	 {
	 	if(m!=matrix[i][j-1]&&m!=matrix[i-1][j])
	 	{	
	 		 cout<<weight[i]<<" ";
             i--;
             j-=weight[i];            
	    }
	    else if(m==matrix[i][j-1])
	    	j--;
	    else if(m==matrix[i-1][j])
	    	i--;
	    m=matrix[i][j];
}
}
int main()
{
     int weight[4]={1,3,4,5};
     int value[4]={1,4,5,7};
     for(int i=0;i<4;i++)
       {
       	 for(int j=0;j<=7;j++)
       	 	matrix[i][j]=0;
       }
    //  print(matrix);
     knapsack(matrix,weight,value);
     indexes(matrix,weight);
}
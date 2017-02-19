#include<bits/stdc++.h>
using namespace std;
void print(int matrix[7][6],int length,int length1)
{
	 for(int i=0;i<length1+1;i++)
	 {
	 	for(int j=0;j<length+1;j++)
	 	{
	 		 cout<<matrix[i][j]<<" ";
	 	}
	 	cout<<"\n";
	 }
}
void longest(int matrix[7][6],int length,int length1,char s[],char s1[])
{
	 for(int i=0;i<length+1;i++)
	 {
	 	matrix[0][i]=0;
	 }
	 for(int j=0;j<length1+1;j++)
	 {
	 	 matrix[j][0]=0;
	 }
	 cout<<matrix[1][0]<<matrix[2][0];
	 cout<<"\n";
	for(int i=1;i<length1+1;i++)
	{
		 for(int j=1;j<length+1;j++)
		 {
		 	if(j==0)
		 		 cout<<"ere";
            if(s1[i-1]==s[j-1])
            {
            	matrix[i][j]=1+matrix[i-1][j-1];
            }
            else
            {
            	 matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
            }
		 }
	}
	//cout<<matrix[1][0]<<matrix[2][0];
	print(matrix,length,length1);
}
int main()
{
	 char s[]="abcdaf";
	 char s1[]="acbcf";
	 int length=strlen(s);
	 int length1=strlen(s1);
	 int matrix[7][6];
	 longest(matrix,length,length1,s,s1);
	 return 0;
}
#include<iostream>
#define N 4
using namespace std;
void display(int r[][N])
{
	for(int i=0;i<N;i++)
	{
		 for(int j=0;j<N;j++)
		 {
		 	 cout<<r[i][j]<<" ";
		 }
		cout<<endl;
	}
}
void transitive(int g[][N])
{
	int r[N][N];
	for(int i=0;i<N;i++)
	{
		 for(int j=0;j<N;j++)
		   r[i][j]=g[i][j];
	}
	for(int k=0;k<N;k++)
	{
		 for(int i=0;i<N;i++)
		 {
		 	 for(int j=0;j<N;j++)
		 	 {
		 	 	 r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
			  }
		 }
	}
	display(r);
}
int main()
{
	 int g[N][N]={{1,1,0,1}
	             ,{0,1,1,0}
	             ,{0,0,1,1}
	             ,{0,0,0,1}
				 };
	transitive(g);
}

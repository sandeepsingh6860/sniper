#include<iostream>
using namespace std;
#define N 3
int getmax(int amount[N])
{
	int a=0;
	for(int k=1;k<N;k++)
	{
		if(amount[k]>amount[a])
		 a=k; 
	}
  return a;
}
int getmin(int amount[])
{
	int a=0;
	for(int k=1;k<N;k++)
	{
		 if(amount[k]<amount[a])
		    a=k;
	}
  return a;
}
int min(int a,int b)
{
	 if(a>=b)
	 return a;
	 else
	   return b;
}
void calcash(int amount[])
{
	int mxcredit=getmax(amount);//it gets the index of maximum creditor
	int mxdebit=getmin(amount);// it gets the index of maximum debitor
	
	if(amount[mxcredit]==0&&amount[mxdebit]==0)
	 return;
	int pi=min(amount[mxcredit],-amount[mxdebit]);
	int c=-amount[mxdebit];
	amount[mxdebit]+=pi;
	amount[mxcredit]-=pi;
	cout<<"person" <<mxdebit<<"payed rupees = "<<c<< "to person" <<mxcredit<<endl;
	calcash(amount);
}
void mincashflow(int g[N][N])
{
	int amount[N]={0};
	
	for(int p=0;p<N;p++)
	{
		for(int i=0;i<N;i++)
		{
			amount[p]+=(g[i][p]-g[p][i]);
		}
	}
	calcash(amount);
}

int main()
{
	int g[N][N]={{0,1000,2000},
	              {0,0,5000},
				  {0,0,0},};
	mincashflow(g);	
	return 0;
}

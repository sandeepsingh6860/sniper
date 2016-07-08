#include<iostream>
#include<queue>
using namespace std;
#define V 4
bool isbipaptite(int g[][V],int src)
{
	 int color[V];
	 
	 for(int j=0;j<V;j++)
	   color[j]=-1;
	   
	 color[src]=1;
	 
	 queue<int>q;
	 q.push(src);
	 
	 while(q.empty()!=false)
	  {
	  	 int u=q.front();
	  	 q.pop();
	  	 for(int v=0;v<V;v++)
	  	 {
	  	 	if(g[u][v]==1&&color[v]==-1)
	  	 	 {
			   color[v]=1-color[u];
	  	 	   q.push(v);
	  	     }
	  	 	else if(g[u][v]==1&&color[u]==color[v])
	  	 	    return false;
		 }
	  }
	return true;
}
int main()
{
    int g[][V]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
	bool i;	
	i=isbipaptite(g,0);
	cout<<i<<" ";
	return 0;
}

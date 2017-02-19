#include<bits/stdc++.h>
using namespace std;
#define V 4 
#define INF 10000
void printTrans(int g[V][V])
{
    for(int i=0;i<V;i++)
    {
    	 for(int j=0;j<V;j++)
    	 {
    	 	 if(g[i][j]==INF)
    	 	 	cout<<"~"<<" ";
    	 	 else
    	 	 	 cout<<g[i][j]<<" ";
    	 }
    cout<<"\n";
    }
}
void floyd_warshall(int graph[V][V])
{
	 int distance[V][V];
	 for(int i=0;i<V;i++)
	 {
	 	 for(int j=0;j<V;j++)
	 	 	distance[i][j]=graph[i][j];
	 }
	for(int k=0;k<V;k++)
	{
		 for(int i=0;i<V;i++)
		 {
		 	for(int j=0;j<V;j++)
		 	{
		 		if(distance[i][j]>distance[i][k]+distance[k][j])
		 			distance[i][j]=distance[i][k]+distance[k][j];
		 	}
		 }
	}
  printTrans(distance);
}
int main()
{
	 int graph[V][V]={ {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
     floyd_warshall(graph);
}
#include<iostream>
using namespace std;
#define N 9
#define INF 1000
int findmin(bool visited[N],int distance[N])
{
	 long int max=100000;
	 int maxindex;
	 for(int v=0;v<N;v++)
	  {
	  	 if(visited[v]==false&&distance[v]<max)
	  	  {
	  	  	 max=distance[v];
	  	  	 maxindex=v;
		  }
	  }
	return maxindex;
}
void printgraph(int distance[N])
{
	  cout<<"THE DISTANCES ARE = ";
	 for(int i=0;i<N;i++)
	  {
	  	cout<<i<<" "<<distance[i]<<endl;
	  }
}
void dijikstra(int g[][N],int src)
{
	bool visited[N];
	int distance[N];
	for(int i=0;i<N;i++)
	{
	  visited[i]=false;
	  distance[i]=INF;
    }
     distance[src]=0;
  for(int count=0;count<N-1;count++)
  {
	int u=findmin(visited,distance);
	visited[u]=true;
    for(int v=0;v<N;v++)
    {
    	 if(visited[v]==false&&distance[u]+g[u][v]<distance[v]&&g[u][v])
    	     distance[v]=distance[u]+g[u][v];
	}
  }
   printgraph(distance);
}
int main()
{
	 int g[N][N]=  {  {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0},
				  };
    dijikstra(g,0);
    return 0;
}

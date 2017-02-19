#include<bits/stdc++.h>
using namespace std;
#define V 9
#define INF 10000
void print(int distance[V])
{
	for(int i=0;i<V;i++)
	{
		 cout<<distance[i]<<" ";
	}
}
int min(int distance[V],int spt[V])
{
	 int minimum=INF;
	 int minindex;
	 for(int i=0;i<V;i++)
	 {
	 	 if(distance[i]<=minimum&&spt[i]==0)
	 	 {
	 	 	 minimum=distance[i];
	 	 	 minindex=i;
	 	 }
	 }
	 return minindex;
}
void dijikstas(int g[V][V])
{
	 int spt[V],distance[V];
	 for (int i = 0; i < V; ++i)
	 {
	 	spt[i]=0;
	 	distance[i]=INF;
	 }
    distance[0]=0;
    for(int i=0;i<V-1;i++)
    {
    	 int key=min(distance,spt);
    	 spt[key]=1;
    	 for(int i=0;i<V;i++)
    	 {
    	 	 if(spt[i]==0&&g[key][i]&&distance[key]+g[key][i]<distance[i])
    	 	 	distance[i]=distance[key]+g[key][i];
    	 }
    }
    print(distance);
}
int main()
{
	int g[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                 {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijikstas(g);
	return 0;
}
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//void union(int parent[],int i,int j);
struct edge
{
	int source;
	int dest;
};

struct graph
{
	struct edge*EDGE;//array of edges
	int V,E;
};
struct graph*creategraph(int V,int E)
{
	struct graph*g=(struct graph*)malloc(sizeof(struct graph));
	g->V=V;
	g->E=E;
	g->EDGE=(struct edge*)malloc(sizeof(struct edge)*E);
	return g;
}
int find(int parent[],int i)
{
	if(parent[i]==-1)
	  return i;
	else 
	  return find(parent,parent[i]);
}
void union(int parent[],int i,int j)
{
	  int x=find(parent,i);
	  int y=find(parent,j);
	 parent[x]=y;    
}
int findcycle(struct graph*g)
{    int i;
	 int*parent=(int*)malloc(sizeof(int)*g->V);
	 memset(parent,-1,sizeof(int)*g->V);
	 for(int k=0;k<g->E;k++)
	 {
	 	int s=find(parent,g->EDGE[i].source);
	 	int v=find(parent,g->EDGE[i].dest);
	 	if(s==v)
	 	 return 1;
	 	 
		 union(parent,s,v);
	 }
  return 0;
}
int main()
{
	int V,E;
	V=3;
	E=3;
	struct graph*g=creategraph(V,E);
	g->EDGE[0].source=0;
	g->EDGE[0].dest=1;
	
	g->EDGE[1].source=1;
	g->EDGE[1].dest=2;
	
	g->EDGE[2].source=2;
	g->EDGE[2].dest=0;
	
	if(findcycle(g))
	  cout<<"YES THERE ARE CYCLES IN THE GRAPH";
	 else
	  cout<<"NO!CYCLE PRESENT"; 
	return 0;
}

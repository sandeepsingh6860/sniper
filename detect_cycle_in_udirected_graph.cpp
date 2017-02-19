#include<bits/stdc++.h>
using namespace std;
struct edge
{
   int src,dest;
};
struct graph
{
   int V,E;
   struct edge*e;
};
struct graph*createGraph(int number,int edges)
{
   struct graph*g=(struct graph*)malloc(sizeof(struct graph));
   g->V=number;
   g->E=edges;
   struct edge*e1=(struct edge*)malloc(sizeof(struct edge)*g->E);
   g->e=e1;
   return g;
}
int find(int parent[],int index)
{
	 if(parent[index]==-1)
	 	 return index;
	 return find(parent,parent[index]);
}
void union1(int parent[],int srcindex,int destindex)
{
	// int index=find(parent,srcindex);
	// int index1=find(parent,destindex);
	 parent[srcindex]=destindex;
}
int cycleun(struct graph*g)
{
	int v=g->V;
	int*parent=new int[v];
	for(int i=0;i<v;i++)
		parent[i]=-1;
    for(int i=0;i<g->E;i++)
    {
    	 int srcindex=find(parent,g->e[i].src);
    	 int destindex=find(parent,g->e[i].dest);
    	 if(srcindex==destindex)
    	 	 return 1;
    	 union1(parent,srcindex,destindex);
    }
    return 0;
}
int main()
{
	 int v=3,e=2;
     struct graph*g=createGraph(v,e);
     // add edge 0-1
     g->e[0].src=0;
     g->e[0].dest=1;
     // add edge 1-2
     g->e[1].src=1;
     g->e[1].dest=2;
     // add edge 0-2
  //   g->e[2].src=0;
    // g->e[2].dest=2;

     cout<<cycleun(g);
	 return 0;
}
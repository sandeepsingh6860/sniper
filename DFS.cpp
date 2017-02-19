#include<bits/stdc++.h>
using namespace std;
struct graph
{
   int V;
   list<int>*adj;
};
struct graph*createGraph(int v)
{
     struct graph*g=(struct graph*)malloc(sizeof(struct graph));
     g->V=v;
     g->adj=new list<int>[v];
     return g;
}
void addEdge(struct graph*g,int src,int dst)
{
    g->adj[src].push_back(dst);
}
void DfsUtil(struct graph*g,int start,bool visited[])
{
    visited[start]=true;
    cout<<start<<" ";
    list<int>::iterator it;
    for(it=g->adj[start].begin();it!=g->adj[start].end();it++)
      {
      	  if(!visited[*it])
          DfsUtil(g,*it,visited);
      }
}
void DFS(struct graph*g,int start)
{
	 int v=g->V;
	 bool*visited=new bool[v];
	 for(int i=0;i<v;i++)
	 	visited[i]=false;
	 DfsUtil(g,start,visited);
}
int main()
{
     int v,ch,src,dst,start;
	 cout<<"ENTER THE TOTAL VERTEX";
	 cin>>v;
	 struct graph*g=createGraph(v);
	 cout<<"GRAPH CREATED\n";
	 cout<<"NOW YOU CAN ENTER EDGES PAIR\n";
	  do
	  {
	    cin>>src>>dst;
	    addEdge(g,src,dst);
	    cout<<"WANT TO ENTER MORE(1 for 'YES' 0 for 'NO')";
	    cin>>ch;
	  }while(ch!=0);
     cout<<"ENTER THE STARTING VERTEX";
     cin>>start;
     DFS(g,start);
}
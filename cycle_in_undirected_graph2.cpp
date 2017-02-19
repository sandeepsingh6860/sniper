#include<bits/stdc++.h>
using namespace std;
struct graph
{
    int V;
    list<int>*adj;
};
struct graph*createGraph(int number)
{
   struct graph*g=(struct graph*)malloc(sizeof(struct graph));
   g->V=number;
   list<int>*l=new list<int>[number];
   g->adj=l;
   return g;
}
void addEdge(struct graph*g,int start,int end)
{
	g->adj[start].push_back(end);
	g->adj[end].push_back(start);
}
bool cycleutil(struct graph*g,bool visited[],int parent,int i)
{
      visited[i]=true;
      list<int>::iterator it;
      for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
      {
      	  if(visited[*it]==false)
      	  {
      	  	   return cycleutil(g,visited,i,*it);
      	  }
      	  else if(*it!=parent)
      	  	return true;
      }
      return false;
}
bool cycle(struct graph*g)
{
	 int v=g->V;
	 bool*visited=new bool[v];
	 for(int i=0;i<v;i++)
	 	visited[i]=false;
	 for(int i=0;i<v;i++)
	 {
	 	 if(visited[i]==false)
	 	 	{
	 	 		 if(cycleutil(g,visited,-1,i))
	 	 		 	return true;
	 	 	}
	 }
	 return false;
}
int main()
{
	 int number,start,end,ans;
	 cout<<"ENTER THE NO OF VERTICES\n";
	 cin>>number;
     struct graph*g=createGraph(number);
     cout<<"GRAPH CREATED SUCCESSFULLY\n";
     do
     {
     	 cout<<"enter the starting and ending vertex and weight\n";
     	 cin>>start>>end;
     	 addEdge(g,start,end);
     	 cout<<"DO YOU WANT TO ENTER MORE(1/0)\n";
     	 cin>>ans;
     }while(ans!=0);
     cout<<cycle(g);
}
#include<bits/stdc++.h>
#define NINF INT_MIN
using namespace std;
struct adjnode
{
   int v;
   int weight;
};
struct graph 
{
   int V;
   list<adjnode>*adj;
};
struct graph*createGraph(int number)
{
   struct graph*g=(struct graph*)malloc(sizeof(struct graph));
   g->V=number;
   list<adjnode>*l=new list<adjnode>[number];
   g->adj=l;
   return g;
}
void addEdge(struct graph*g,int start,int end,int weight1)
{
	struct adjnode*a;
	a->v=end;
	a->weight=weight1;
	g->adj[start].push_back(a);
}
void topologicalSortUtil(struct graph*g,int i,bool visited[],stack<int>&st)
{
    visited[i]=true;
    list<int>::iterator it;
    for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
    {
    	 if(visited[*it]==false)
    	 	topologicalSortUtil(g,*it,visited,st);
    }
   st.push(i);
}
/*void topologicalSort1(struct graph*g)
{
	 stack<int>st;
	 int v=g->V;
	 bool*visited=new bool[v];
	 for(int i=0;i<v;i++)
	   visited[i]=false;
	 for(int i=0;i<v;i++)
	    {
	    	 if(visited[i]==false)
	    	 	topologicalSortUtil(g,i,visited,st);
	    }
	  int distance=new int[v];
	  for(int i=0;i<v;i++)
	  	 distance[i]=NINF;
	  distance[source]=0;
	  while(st.empty()==false)
	  {
	  	 int data=st.top();
	  	 st.pop();
	  	 list<adjnode>::iterator it;
	  	 if(distance[data]!=NINF)
	  	{
	  	 for(it=g->adj[data].begin();it!=g->adj[data].end();it++)
	  	 {
            if(distance[(*it)->v]<distance[data]+it->weight)
            	distance[(*it)->v]=distance[data]+it->weight;
	  	 }
	  }
}
}*/
/*void print(struct graph*g)
{
	 int v=g->V;
	 list<int>::iterator it;
	 for(int i=0;i<v;i++)
	  {
	  	 cout<<"THE ADJLIST OF "<<i<<"is";
	  	 for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
	  	 	cout<<*it<<" ";
	  	cout<<"\n";
	  }
}*/
void longest_path_in_DAG(struct graph*g,int source)
{
     stack<int>st;
	 int v=g->V;
	 bool*visited=new bool[v];
	 for(int i=0;i<v;i++)
	   visited[i]=false;
	 for(int i=0;i<v;i++)
	    {
	    	 if(visited[i]==false)
	    	 	topologicalSortUtil(g,i,visited,st);
	    }
	  int*distance=new int[v];
	  for(int i=0;i<v;i++)
	  	 distance[i]=NINF;
	  distance[source]=0;
	  while(st.empty()==false)
	  {
	  	 int data=st.top();
	  	 st.pop();
	  	 list<adjnode>::iterator it;
	  	 if(distance[data]!=NINF)
	  	{
	  	 for(it=g->adj[data].begin();it!=g->adj[data].end();it++)
	  	 {
            if(distance[(it)->v]<distance[data]+it->weight)
            	distance[(it)->v]=distance[data]+it->weight;
	  	 }
	  }
}
for(int i=0;i<v;i++)
{
	 (distance[i]==NINF)?cout<<"INF":cout<<distance[i]<<" ";
}
}
int main()
{
	 int number,start,end,ans,source,w;
	 cout<<"ENTER THE NO OF VERTICES\n";
	 cin>>number;
     struct graph*g=createGraph(number);
     cout<<"GRAPH CREATED SUCCESSFULLY\n";
     do
     {
     	 cout<<"enter the starting and ending vertex and weight\n";
     	 cin>>start>>end>>w;
     	 addEdge(g,start,end,w);
     	 cout<<"DO YOU WANT TO ENTER MORE(1/0)\n";
     	 cin>>ans;
     }while(ans!=0);
     cout<<"ENTER THE SOURCE VERTEX";
     cin>>source;
    longest_path_in_DAG(g,source);
	 return 0;
}
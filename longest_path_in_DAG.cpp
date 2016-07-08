#include<iostream>
#include<list>
#include<stack>
#include<limits.h>
#define infinity INT_MIN
using namespace std;
class adjlist
{
	 int v;
	 int weight;
	 
  public:
  	      adjlist(int v,int w)
			{
				 v=v;
				 weight=w;
			 }
		  int getv()
		  {
		  	 return v;
		   } 
		 int getweight()
		 {
		 	 return weight;
		 }
};
class graph
{
	int V;
	
	list<adjlist>*adj;
	
  public:
  	        graph(int V)
  	        {
  	        	this->V=V;
  	            adj=new list<adjlist>[V];	
			}
		   void addvertex(int u,int v,int w)
		   {
		   	     adjlist node(v,w);
		   	     adj[u].push_back(node);
		   }
		   void topological(int v,bool visited[],stack<int>&Stack)
		   {
		   	    visited[v]=true;
		   	    
		   	    list<adjlist>::iterator i;
		   	    
		   	    for(i=adj[v].begin();i!=adj[v].end();i++)
		   	     {
		   	        adjlist node=*i; 
		   	        if(!visited[node.getv()])
					 	topological(node.getv(),visited,Stack);  	
				 }
				Stack.push(v);
		   }
		  void longestpath(int s)
		  {
		  	 stack<int>Stack;
		  	
		  	 int dist[V];
		  	 
		  	 bool*visited=new bool[V];
		  	 
		  	 for(int j=0;j<V;j++)
		  	    visited[j]=false;
		  	  
		  	for(int k=0;k<V;k++)
		  	    dist[k]=infinity;
		  	   dist[s]=0;
			for(int i=0;i<V;i++) 
			{
				  if(visited[i]==false)
				     topological(i,visited,Stack);
			}
	     while(Stack.empty()==false)  
		   	 {
		   	 	int u=Stack.top();
		   	 	Stack.pop();
		   	 	
		   	 	list<adjlist>::iterator temp;
		   	 if(dist[u]!=infinity)
		   	 {
		   	 	for(temp=adj[u].begin();temp!=adj[u].end();temp++)
		   	 	{
		   	 	    if(dist[temp->getv()]<dist[u]+temp->getweight())
						dist[temp->getv()]=dist[u]+temp->getweight();
				}
		     }
          }
        for(int j=0;j<V;j++)
         (dist[j]==infinity)?cout<<"INF":cout<<dist[j]<<" ";
}
};
int main()
{
	graph g(6);
	
	g.addvertex(0,1,5);
	g.addvertex(0,2,3);
	g.addvertex(1,3,6);
	g.addvertex(1,2,2);
	g.addvertex(2,4,4);
	g.addvertex(2,5,2);
	g.addvertex(2,3,7);
	g.addvertex(3,5,1);
	g.addvertex(3,4,-1);
	g.addvertex(4,5,-2);
	int s=1;
	cout<<"THE LONGEST DISTANCE FROM SOURCE VERTEX IS"<<s<<"\n";
	g.longestpath(s);
	return 0;	
}

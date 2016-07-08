#include<iostream>
#include<list>
using namespace std;

class graph
{ 
    int V,i;
	
	list<int>*next;	
	
	public:
		     graph(int V)
		     {
		     	 this->V=V;
		     	 next=new list<int>[V];
			 }
		void dfsutil(int v,bool visited[])
			  {
			     visited[v]=true;
				 
				 cout<<v<<" ";
				 
				 list<int>::iterator temp;
				 
				 for(temp=next[v].begin();temp!=next[v].end();temp++)
				 {
				   if(!visited[*temp])
				     dfsutil(*temp,visited); 	
				 }	 	
			    }
		void addvertex(int v,int w)
			{
				next[v].push_back(w);
		    }
		void dfs1(int v)
		{
		   bool *visited=new bool[V];
		   for(i=0;i<V;i++)	
		 	visited[i]=false;
			dfsutil(v,visited);
		}	
};
int main()
{
	graph g(4);
	
	g.addvertex(0,1);
	g.addvertex(0,2);
	g.addvertex(1,2);
	g.addvertex(2,0);
	g.addvertex(2,3);
	g.addvertex(3,3);
	
	cout<<"THE DFS OF THE GRAPH IS";
	
	g.dfs1(2);
		
	return 0;
}


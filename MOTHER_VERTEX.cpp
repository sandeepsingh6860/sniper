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
}
void dfsutil(struct graph*g,int i,bool visited[])
{
     visited[i]=true;
     
     list<int>::iterator it;

     for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
     {
     	  if(visited[*it]==false)
     	  	 dfsutil(g,*it,visited);
     }
}



int find_mother(struct graph*g)
{
	   int v=g->V,vertex;
       bool*visited=new bool[v];
       for(int i=0;i<v;i++)
       	 visited[i]=false;
       for(int i=0;i<v;i++)
       {
       	     if(visited[i]==false)
       	     {
       	     	  dfsutil(g,i,visited);
       	     	  vertex=i;
       	     }
       }
// NOW CHECK THIS VERTEX AS MOTHER VERTEX
// FIRST REINITIALIZE THE BOOLEAN ARRAY
       bool*visited1=new bool[v];

       for(int i=0;i<v;i++)
       	visited1[i]=false;

       dfsutil(g,vertex,visited1);

       for(int i=0;i<v;i++)
       	 {
       	 	 if(visited1[i]==false)
       	 	 	return -1;
       	 }
       	 return vertex;
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
    cout<<find_mother(g);
    return 0;
}

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
bool dfs(struct graph*g,bool visited[],int s,int vdegree[],int k)
{
	 visited[s]=true;
	 list<int>::iterator it;
	 for(it=g->adj[s].begin();it!=g->adj[s].end();it++)
	 {
	 	  if(vdegree[s]<k)
	 	  	 vdegree[*it]--;
	 	   if(visited[*it]==false)
	 	   {
	 	   	   if(dfs(g,visited,*it,vdegree,k));
	 	   	   vdegree[s]--;
	 	   }
	 }
	 if(vdegree[s]<k)
	 	return true;
	 else
	 	 return false;
}
void printKcores(struct graph*g,int k)
{
	  int v=g->V,startvertex;
	  int mindegee=INT_MAX;
      bool*visited=new bool[v];
      int*vdegree=new int[v];
      for(int i=0;i<v;i++)
      	 visited[i]=false;
      for(int i=0;i<v;i++)
      {
           vdegree[i]=g->adj[i].size();
           if(vdegree[i]<mindegee)
           {
           	   mindegee=vdegree[i];
           	   startvertex=i;
           }
      }
      dfs(g,visited,startvertex,vdegree,k);
   // now changing the powers of other vertices
      for(int i=0;i<v;i++)
      {
      	  if(visited[i]==false)
      	  {
      	  	 dfs(g,visited,i,vdegree,k);
      	  }
      }
      cout<<"PRINT K CORES";
      for(int i=0;i<v;i++)
      {
      	   if(vdegree[i]>=k)
      	{
      	   	 cout<<i<<"-->";
           list<int>::iterator it;
      	   	for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
      	   	{
      	   		 if(vdegree[*it]>=k)
      	   		 	cout<<*it<<"-->";
      	   	}
      	}
     }
}
int main()
{
     int number,start,end,ans,k;
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
     cout<<"enter the core";
     cin>>k;
     printKcores(g,k);
 }

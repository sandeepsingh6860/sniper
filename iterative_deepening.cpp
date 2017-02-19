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
bool ids(struct graph*g,int start,int target,int depth)
{
   if(start==target)
   	 return true;
   if(depth<0)
   	 return false;
   list<int>::iterator it;
   for(it=g->adj[start].begin();it!=g->adj[start].end();it++)
   {
   	   if(ids(g,*it,target,depth-1)==true)
   	   	 return true;
   }
   return false;
}
bool idfs(struct graph*g,int start,int target,int maxdepth)
{
     for(int i=0;i<=maxdepth;i++)
     {
     	 if(ids(g,start,target,i)==true)
     	 	 return true;
     }
   return false;
}
int main()
{
	 int number,start,end,ans,k,target;
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
     cout<<"enter the source";
     cin>>k;
     cout<<"enter the target to which u want to move";
     cin>>target;
     int maxdepth=3;
     if(idfs(g,k,target,maxdepth)==true)
     	cout<<"SURELY YOU CAN MOVE TO TARGET VERTEX WITHIN MAXDEPTH\n";
     else
     	 cout<<"SORRY U CAN'T";
    return 0;
}
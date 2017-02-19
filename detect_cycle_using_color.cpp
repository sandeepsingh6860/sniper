#include<bits/stdc++.h>
using namespace std;
enum COlOR
{
   WHITE,GREY,BLACK 
};
struct graph
{
   int V;
   list<int>*adj;
};
struct graph*createGraph(int V)
{
	 struct graph*g=(struct graph*)malloc(sizeof(struct graph));
	 g->V=V;
	 list<int>*l1=new list<int>[V];
	 g->adj=l1;
	 return g;
}
void addEdge(struct graph*g,int src,int dest)
{
    g->adj[src].push_back(dest);
}
bool dfsutil(struct graph*g,int color[],int u)
{
    color[u]=GREY;
    list<int>::iterator it;
    for(it=g->adj[u].begin();it!=g->adj[u].end();it++)
    {
    	 if(color[*it]==GREY)
    	 	return true;
    	 if(color[*it]==WHITE&&dfsutil(g,color,*it))
    	 	return true;
    }
    color[u]=BLACK;
    return false;
} 
bool detect_loop(struct graph*g)
{
	 int v=g->V;
	 int*color=new int[v];
	 for(int i=0;i<v;i++)
	 {
        color[i]=WHITE;   
	 }
     for(int i=0;i<v;i++)
     {
     	 if(color[i]==WHITE)
     	 {
     	 	if(dfsutil(g,color,i)==true)
     	 		return true;
     	 }
     }
    return false;
}
int main()
{
	int v,ans,start,end;
	cout<<"Enter the total vertices\n";
	cin>>v;
    struct graph*g=createGraph(v);
    cout<<"GRAPH CREATED SUCCESSFULLY\n";
     do
     {
     	 cout<<"enter the starting and ending vertex and weight\n";
     	 cin>>start>>end;
     	 addEdge(g,start,end);
     	 cout<<"DO YOU WANT TO ENTER MORE(1/0)\n";
     	 cin>>ans;
     }while(ans!=0);
    cout<<detect_loop(g);
	return 0;
}
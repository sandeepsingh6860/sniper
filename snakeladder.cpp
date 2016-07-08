#include<iostream>
#include<queue>
using namespace std;
struct queuet
{
	 int v;
	 int d;
};
int noofsteps(int move[],int N)
{
	bool *visited=new bool[N];
	for(int j=0;j<N;j++)
	  visited[j]=false;
	  
	//int distance[N];
		  
	visited[0]=true;
	
    queue<queuet>q;
		
	 queuet s={0,0};  //first entry is the vertex no,second no is the distance from the source
	
	q.push(s);
	
	queuet qt;
	
	while(!q.empty())
	{
		qt=q.front();
		
		int V=qt.v; 
		
		if(qt.v==N-1)
		   break;
		 
		 q.pop();
		 
		for(int j=V+1;j<=(V+6)&&j<N;j++)
		{
			if(!visited[j])
			{
				queuet a;
				a.d=(qt.d)+1;
				visited[j]=true;
				if(move[j]!=-1)
				 a.v=move[j];
				 else
				   a.v=j;
				q.push(a);
			}
		}
	}
	return qt.d;
}

int main()
{
	int N=100,i;
//	cout<<"ENTER THE TOTAL NO OF BLOCKS";
//	cin>>N;
	int move[N];
	for(int j=0;j<N;j++)
	  move[j]=-1;
	//LADDERS
	move[7]=98;
	move[99]=2;
	/* move[10]=25;
	move[19]=28;
	// SNAKES
	move[26]=0;
	move[20]=8;
	move[16]=3;
	move[18]=6;  */
	
	i=noofsteps(move,N);
	cout<<i;
	return 0;
}

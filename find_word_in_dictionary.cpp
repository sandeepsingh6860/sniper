#include<iostream>
using namespace std;
#define N 3
string dict[]={"GEEKS","FOR","QUIZ","GO"};
int n=sizeof(dict)/sizeof(dict[0]);
bool com(string &str)
{
    for(int i=0;i<n;i++)
      {
      	  if(str.compare(dict[i])==0)
      	    return true;
	  }
	  return false;
}
void isword(char g[N][N],bool visited[N][N],int i,int j,string &str)
{
	visited[i][j]=true;
	str=str+g[i][j];
	
	if(com(str))
	  cout<<str<<endl;
	for(int row=i-1;row<=i+1&&row<N;row++)
	{
		for(int col=j-1;col<=j+1&&col<N;col++)
		{
			if(row>=0&&col>=0&&!visited[row][col])
			     isword(g,visited,row,col,str);
		}
	 } 
	str.erase(str.length()-1);
	  visited[i][j]=false;
}
void findw(char g[][N])
{
	bool visited[N][N]={"false"};
	
	string str="";
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		 {
		 	isword(g,visited,i,j,str);
		 }
	}
}

int main()
{   
    char g[N][N]={{'G','I','Z'},
	             {'U','E','K'},
	             {'Q','S','E'}};
	cout<<"WORDS ARE";
	findw(g);
	return 0;
}

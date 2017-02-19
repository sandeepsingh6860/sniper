#include<bits/stdc++.h>
using namespace std;
struct stack1
{
    int min;
    stack<int>st;
    void push(int x)
    {
       if(st.empty()==true)
       {
       	   st.push(x);
       	   min=x;
       }
       else
       {
       	  if(x>=min)
       	  {
       	  	 st.push(x);
       	  }
       	  else
            {
            	 int a=2*x-min;
            	 st.push(a);
            	 min=x;
            }
       }
    }
    void pop()
    {
      int y;
    	 if(st.empty()==true)
    	 	cout<<"STACK IS ALREADY EMPTY"<<"\n";
    	 else
    	 {
    	 	 y=st.top();
    	 	 st.pop();
    	 	 if(y<min)
    	 	 {
    	 	 	 min=2*min-y;
    	 	 }
    	 }
      // cout<<y;
    }
   void getMin()
   {
   	 cout<<"THE MINIMUM ELEMENT IS "<<min<<" "<<"\n";
   }
   void peek()
   {
   	 cout<<"THE TOP MOST ELEMENT IS "<<st.top()<<"\n";
   }
};
int main()
{
	stack1 s;
	s.push(79);
  s.getMin();
  s.push(4);
  s.getMin(); 
  s.getMin();
  s.pop();
  s.push(61);
  s.getMin();
}
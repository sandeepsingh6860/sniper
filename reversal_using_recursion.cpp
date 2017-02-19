#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node*next;
};
struct node*head;
struct node*newnode1(int key)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	return temp;
}
void reversal(struct node*root)
{
     struct node*temp;
     if(root==NULL)
     	return;
     temp=root;
     if(temp->next==NULL)
     {
         head=temp;
         return;
     }
     reversal(temp->next);
     temp->next->next=temp;
     temp->next=NULL;
}
void print(struct node*root)
{
	 while(root)
	  {
	  	 cout<<root->data<<" ";
	  	 root=root->next;
	  }
}
int main()
{
     struct node*root=newnode1(1);
     root->next=newnode1(2);
     root->next->next=newnode1(3);
     root->next->next->next=newnode1(4);
     head=NULL;
     print(root);
     reversal(root);
     print(head);
	 return 0;
}
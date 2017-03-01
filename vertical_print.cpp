#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};
struct node*newNode(int data)
{
	 struct node*temp=(struct node*)malloc(sizeof(struct node));
	 temp->data=data;
	 temp->left=NULL;
	 temp->right=NULL;
	 return temp;
}
void getDistance(struct node*root,int*max,int*min,int currentd)
{
	 if(root==NULL)
	 	return ;
	 if(*min>currentd)
	 	 *min=currentd;
	 if(*max<currentd)
	 	 *max=currentd;
	 getDistance(root->left,max,min,currentd-1);
	 getDistance(root->right,max,min,currentd+1);
}
void printVertical(struct node*root,int i,int currentd)
{
	 if(root==NULL)
	 	 return;
	 if(i==currentd)
	 	cout<<root->data<<" ";
	 printVertical(root->left,i,currentd-1);
	 printVertical(root->right,i,currentd+1);
}
void vertical_print(struct node*root)
{
	int max=0,min=0,currentd=0;
	getDistance(root,&max,&min,currentd);  //we will get the minimum and maximum distance from here
    for(int i=min;i<=max;i++)
    {
    	 printVertical(root,i,0);
    	 cout<<"\n";
    }
}
int main()
{
    struct node*root=newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    vertical_print(root);
}
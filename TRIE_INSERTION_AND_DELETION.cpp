#include<bits/stdc++.h>
using namespace std;
#define SIZE1(a) sizeof(a)/sizeof(a[0])
#define max 26
#define CHAR_TO_INT(b) ((int)b-(int)'a')
struct tree
{
   struct tree*alphabet[max];
   bool isleaf;
};
struct tree*createNode()
{
	 struct tree*g=(struct tree*)malloc(sizeof(struct tree));
	 g->isleaf=false;
	 for(int i=0;i<max;i++)
	 {
	 	 g->alphabet[i]=NULL;
	 }
	 return g;
}
void insert(struct tree*root,char key[])
{
	// int length=SIZE(key);
	struct tree*temp;
	temp=root;
	 for(int i=0;key[i]!='\0';i++)
	 {
	 	 int index=CHAR_TO_INT(key[i]);
	 	 if(temp->alphabet[index]==NULL)
	 	 {
	 	 	 temp->alphabet[index]=createNode();
	 	 }
	 	temp=temp->alphabet[index];
	 }
	 temp->isleaf=true;
}
bool search(struct tree*root,const char*key)
{
	 int length=strlen(key);
	// cout<<length;
	 struct tree*temp=root;
	 for(int i=0;i<length;i++)
	 {
	 	 int index=CHAR_TO_INT(key[i]);
	 	 if(temp->alphabet[index]==NULL)
	 	 {
	 	 	 return false; 
	 	 }
	 	 temp=temp->alphabet[index];
	 }
	if(temp!=NULL&&temp->isleaf==true)
		return true;
	else
		 return false;
}
int main()
{ 
     char key[][8]={"the","these","their","those","alpha"};
  //   char output[][32]={"output is obtained","output is not obtained"};
     struct tree*root=createNode();

     int i;

   //  cout<<SIZE1(key[0]);
     for(i=0;i<SIZE1(key);i++)
     {
         insert(root,key[i]);
     }
     cout<<search(root,"theit");
	 return 0;
}
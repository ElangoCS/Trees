#include<iostream>
using namespace std;
struct node
 {
  int data;
  node *left;
  node *right;  
  };

node *getnewnode(int data)
 { 
  node *newnode=new node();
  newnode->data=data;
  newnode->left=newnode->right=NULL;
  return newnode;
}
node *Insert(node* root,int data)
{
 if(root==NULL)
  {
   root=getnewnode(data);
  }
 else if(data<=root->data)
  {
   root->left=Insert(root->left,data);
  }
 else
  {
   root->right=Insert(root->right,data);
  }
return root;
}
node *display(node *root)
{
 while(root->left!=NULL)
 {
  cout<<root->data;
  root=root->left;
  cout<<"***";
 }
}
bool Search(node *root,int data)
 {
  if(root==NULL)
   return false;
  else if(root->data==data)
   return true;
  else if(data<=root->data)
   return Search(root->left,data);
  else
   return Search(root->right,data); 
 }
int main()
{
node *root;
root=NULL;
root=Insert(root,14);
root=Insert(root,11);
root=Insert(root,89);
root=Insert(root,10);
root=Insert(root,9);
int number;
cout<<"enter the number to be searched";
cin>>number;
if(Search(root,number)==true)
 cout<<"\nfound";
else
 cout<<"not found\n";
display(root);
}


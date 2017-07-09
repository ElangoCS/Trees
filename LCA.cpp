//Reversing the linked list by size break
#include<bits/stdc++.h>

using namespace std;
typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;
node* newnode(int data){
  node *newnod=(node*)malloc(sizeof(struct node));
  newnod->data=data;
  newnod->left=newnod->right=NULL;
  return newnod;
}
node* insert(node *root,int data){
  if((root)==NULL){
    root=newnode(data);
  }
  else{
    if(data<root->data){
      root->left=insert(root->left,data);
    }
    if(data>root->data){
      root->right=insert(root->right,data);
  }
  }
  return root;
}

node* LCA(node *root,int n1,int n2){
  if(root->data>max(n1,n2)){
    return LCA(root->left,n1,n2);
  }
  else if(root->data<min(n1,n2)){
    return LCA(root->right,n1,n2);
  }
  else{
    return root;
  }
}
int display(node *root){
  if(root==NULL){
    return 0;
  }
  display(root->left);
  cout<<root->data;
  display(root->right);
}
int main(){
  int n,data;
  cin>>n;
  node *root=NULL;
  for(int i=0;i<n;i++){
    cin>>data;
    root=insert(root,data);
  }
  cout<<"Before K Rotation"<<endl;
  display(root);
  root=LCA(root,3,7);
  cout<<root->data;
  
}





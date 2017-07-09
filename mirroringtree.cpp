#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;
node* newnode(int data){
  node *n=(node*)malloc(sizeof(struct node));
  n->data=data;
  n->left=n->right=NULL;
  return n;
}
node* insert(node *root,int data){
  if(root==NULL){
    root=newnode(data);
  }
  else{
    if(data>root->data){
      root->right=insert(root->right,data);
    }
    else if(root->data>data){
      root->left=insert(root->left,data);
    }
  }
  return root;
}
void display(node *root){
  if(root!=NULL){
    display(root->left);
    cout<<root->data;
    display(root->right);
  }
}
void mirror(node *root){
  if(root==NULL){
    return;
  }
  mirror(root->left);
  mirror(root->right);
  node *temp;
  temp=root->left;
  root->left=root->right;
  root->right=temp;
}
int main(){
  int n,data;
  node *root=NULL;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>data;
    root=insert(root,data);
  }
  display(root);
  mirror(root);
  cout<<endl;
  display(root);
}


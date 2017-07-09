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


int displayLevelOT(node *root){
  if(root==NULL){
    return 0;
  }
  queue<node*> q;
  q.push(root);
  while(q.empty()==false){
    node *n=q.front();
    cout<<n->data;
    q.pop();
    if(n->left!=NULL){
      q.push(n->left);
    }
    if(n->right!=NULL){
      q.push(n->right);
    }
  }
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
  displayLevelOT(root);
  
  
}


#include <bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;
int height(node *n){
  if(n==NULL){
    return 0;
  }
  return (1+max(height(n->left),height(n->right)));
}
int max(int a,int b){
  return (a>b) ? a:b;
}
int diameter(node *nod){
  if(nod==0){
    return 0;
  }
  int lheight=height(nod->left);
  int rheight=height(nod->right);
  
  int ldiameter=diameter(nod->left);
  int rdiameter=diameter(nod->right);
  
  return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
node* newNode(int a){
  node *Newnode=(node*)malloc(sizeof(struct node));
  Newnode->data=a;
  Newnode->left=Newnode->right=NULL;
  return Newnode;
}
int main(){
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  printf("Diameter of the given binary tree is %d\n", diameter(root));
 
  getchar();
  return 0;
  
}

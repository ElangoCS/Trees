//Elango Kannan
#include<bits/stdc++.h>
using namespace std;
//Structure Definition........
typedef struct AVL{
  int data;
  int height;
  struct AVL *left;
  struct AVL *right;
}AVL;
//AVL Creation of newnode
AVL* newnode(int key){
  AVL *newnod=(AVL*)malloc(sizeof(AVL));
  newnod->data=key;
  newnod->left=newnod->right=NULL;
  newnod->height=1;
  return newnod;
}
//Finding Height.....
int height(AVL *node){
  if(node==NULL){
    return 0;
  }
  return node->height;
}
//Finding balance......
int bal(AVL *node){
  if(node==NULL){
	return 0;
	}
  return (height(node->left)-height(node->right));
}
//Finding Maximum....
int max(int a,int b){
  return (a>b) ? a:b;
}
//left rotation..
AVL* leftRotate(AVL *node){
  AVL *x=node->left;
  AVL *y=x->right;
  x->right=node;
  node->left=y;
  
  //Update the height.......
  node->height = max(height(node->left), height(node->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
  return x;
}
//AVL Right rotate....
AVL* rightRotate(AVL *node){
  AVL *x=node->right;
  AVL *y=x->left;
  x->left=node;
  node->right=y;
  node->height = max(height(node->left), height(node->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
  
  //Update the height.......
  node->height = max(height(node->left), height(node->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
  return x;
}
//AVL INSERTION......
AVL* insert(AVL *node,int key){
  if(node==NULL){
    return (newnode(key));
  }
  else if(key>node->data){
    node->right=insert(node->right,key);
  }
  else if(key<node->data){
    node->left=insert(node->left,key);
  }
  else{
    return node;
  }
  node->height=1+max(height(node->left),height(node->right));
  int balance=bal(node);
  //Checking four conditions.......
  // LeftLeft condition for right rotation
  if(balance>1&&key<node->left->data){
    return rightRotate(node);
  }
  //LeftRight condition for left rotation
  else if(balance<-1&&key>node->right->data){
      return leftRotate(node);
  }
  //LeftRight condition for left right rotation...
  else if(balance>1&&key>node->left->data){
    node->left =  leftRotate(node->left);
        return rightRotate(node);
  }
  //RightLeft condition for right rotation.....
  else if(balance<-1&&key<node->right->data){
    node->right =  rightRotate(node->right);
        return leftRotate(node);
  }
  return node;
}
//Printing in preorder root left right 
void preOrder(AVL *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(){
    AVL *root = NULL;
 
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
 
  return 0;
}

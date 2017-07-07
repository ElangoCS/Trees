#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;
node* BTtoDLL(node *root,node **list_ref){
  if(root==NULL){
    return 0;
  }
  
  BTtoDLL(root->right,list_ref);
  root->right=*list_ref;
  
  if((*list_ref)!=NULL){
    (*list_ref)->left=root;
  }
  
  *list_ref=root;
  
  BTtoDLL(root->left,list_ref);
  
}
node* newNode(int data)
{
    node* newnode = (node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
 
// Utility function for printing double linked list.
void printList(node* head)
{
    printf("Extracted Double Linked list is:\n");
    while (head)
    {
        printf("%d ", head->data);
        head = head->right;
    }
}
 
// Driver program to test above function
int main()
{
    /* Constructing below tree
               5
             /   \
            3     6
           / \     \
          1   4     8
         / \       / \
        0   2     7   9  */
    node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);
 
    node* head = NULL;
    BTtoDLL(root, &head);
 
    printList(head);
 
    return 0;
}

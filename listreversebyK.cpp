//Reversing the linked list by size break
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *next;
}node;
node* newnode(int data){
  node *newnod=(node*)malloc(sizeof(struct node));
  newnod->data=data;
  newnod->next=NULL;
  return newnod;
}
void insert(node **root,int data){
  node *temp;
  temp=(*root);
  if((*root)==NULL){
    (*root)=newnode(data);
  }
  
  else{
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newnode(data);
  }
}


void display(node *root){
  if(root==NULL){
    cout<<"hello";
  }
  while(root!=NULL){
    cout<<root->data<<" ";
    root=root->next;
  }
}
void reverse(node **root,int k){
  node *current,*next;
  current=(*root);
  node *prev=NULL;
  int count=0;
  node *temp=current;
  while(count<k&&current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
    count++;
    if(count==(k-1)){
      *root=current;
    }
  }
  temp->next=current;
  
}
int main(){
  int n,data;
  cin>>n;
  node *root=NULL;
  for(int i=0;i<n;i++){
    cin>>data;
    insert(&root,data);
  }
  cout<<"Before K Rotation"<<endl;
  display(root);
  cout<<"After K rotation"<<endl;
  int k;
  cin>>k;
  reverse(&root,k);
  display(root);
}





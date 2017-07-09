#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y);
class MinHeap{

  int *arr;//ponter to array...
  int h_size;//current size....
  int capacity;//Total capacity of the heap
  public:
    MinHeap(int cap);//constuctor for creating heap;
    
    void MinHeapify(int);
    //for parent node;
    int parent(int i){
      return (1-1/2);
    }
    //for left node;
    int left(int i){
      return (2*i+1);
    }
    //for right node
    int right(int i){
      return (2*i+2);
    }
    //Extracts and deletes the node in the tree
    int extractMIn();
    
    void decreaseKey(int i, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin();
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k);
};

//initializes the capacity of the heap
MinHeap::MinHeap(int cap){
  h_size=0;
  capacity=cap;
  arr=new int[capacity];
}
//Extract the root and removes it
int MinHeap::extractMIn(){
  if(h_size<=0){
    return INT_MIN;
  }
  if(h_size==1){
    h_size--;
    return arr[0];
  }
  int root=arr[0];
  h_size--;
  arr[0]=arr[h_size];
  MinHeapify(0);
  return root;
}
//Decrese the given value and checks for min heap property....
void MinHeap::decreaseKey(int i,int new_val){
  arr[i]=new_val;
  while(i!=0&&arr[i]<arr[parent(i)]){
    swap(&arr[i],&arr[parent(i)]);
    i=parent(i);
  }
}
//get the root element...
int MinHeap::getMin(){
  return arr[0];
}
//Maintains the heap as min hep by checking the left and right
void MinHeap::MinHeapify(int i){
  int l=left(i);
  int r=right(i);
  int smallest=i;
  if (l < h_size && arr[l] < arr[i])
      smallest = l;
  if (r < h_size && arr[r] < arr[smallest])
      smallest = r;
  if (smallest != i)
  {
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::insertKey(int k){
  if(h_size==capacity){
    cout<<capacity;
    printf("Overflow");
    return;
  }
  h_size++;
  int j=h_size-1;
  arr[j]=k;
  
  while(j!=0&&arr[j]<arr[parent(j)]){
    swap(&arr[j],&arr[parent(j)]);
    j=parent(j);
  }
}

void MinHeap::deleteKey(int i){
  decreaseKey(i,INT_MIN);
  extractMIn();
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    MinHeap h(10);
  	h.insertKey(1);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(56);
    h.insertKey(64);
    h.insertKey(75);
    cout << h.extractMIn() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
  

#include<iostream>
using namespace std;
typedef struct queue{
  int front,rear,size;
  unsigned capacity;
  int *array;
}queue;
queue* create(unsigned cap){
  queue *q=(queue*)malloc(sizeof(queue));
  q->capacity=cap;
  q->rear=q->capacity-1;
  q->front=q->size=0;
  q->array=(int*)malloc(q->capacity*sizeof(int));
  return q;
}
bool isfull(queue *q){
  return (q->size==q->capacity);
}
bool isEmpty(queue *q){
  return (q->size==0);
}
void enqueue(queue *q,int data){
  if(isfull(q)){
    return;
  }
  q->rear=(q->rear+1)%q->capacity;
  q->size+=1;
  q->array[q->rear]=data;
}
int dequeue(queue *q){
  if(isEmpty(q)){
    return 0;
  }
  int temp=q->array[q->front];
  q->front=(q->front + 1)%q->capacity;
  q->size=q->size-1;
  return temp;
}

int main(){
  queue *q=create(100);
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  cout<<"dequeued from queue\n"<<dequeue(q);
  cout<<"rear in queue\n";
  cout<<q->array[q->rear];
  cout<<"Front in queue\n";
  cout<<q->array[q->front];
  cout<<"Queue Size";
  cout<<q->size;
}

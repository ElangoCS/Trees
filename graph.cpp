#include <stdio.h>
#include <stdlib.h>
struct lnode{
  int data;
  struct lnode *next;
};
struct anode{
  struct lnode *head;
};
struct Graph{
  int V;
  struct anode *array;
};
struct lnode* newnode(int data){
  struct lnode *newnod =(struct lnode*)malloc(sizeof(struct lnode));
  newnod->data=data;
  newnod->next=NULL;
  return newnod;
}
struct Graph* createGraph(int V){
  struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
  graph->V=V;
  graph->array=(struct anode*)malloc(V* sizeof(struct anode));
  int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
void addEdge(struct Graph *graph ,int src,int dest){
  struct lnode *newNode=newnode(dest);
  newNode->next=graph->array[src].head;
  graph->array[src].head=newNode;
  
  newNode=newnode(src);
  newNode->next=graph->array[dest].head;
  graph->array[dest].head=newNode;
}
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct lnode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}

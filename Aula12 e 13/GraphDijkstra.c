//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphDijkstra - Dijkstra Alg for the Shortest Paths Tree
//

#include "GraphDijkstra.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"
#include "PriorityQueue.h"

struct _GraphDijkstra {
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

// FOR THE PRIORITY QUEUE /////////////////////////////////////////////

// The items in the priority queue will be ID:PRIORITY pairs (type ITEM)

typedef struct {
  int id;   // item id (assigned automatically = index in ITEM array)
  int pri;  // item priority (assigned by the user)
} ITEM;

// The priority comparator for items.
int comparator(const void* p1, const void* p2) {
  return ((ITEM*)p1)->pri - ((ITEM*)p2)->pri;
}

// The printer for items.
void printer(void* p) {
  ITEM* pitem = (ITEM*)p;
  printf("%d:%d", pitem->id, pitem->pri);
}

///////////////////////////////////////////////////////////////////////

GraphDijkstra* GraphDijkstraExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphDijkstra* result = (GraphDijkstra*)malloc(sizeof(struct _GraphDijkstra));
  assert(result != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  // CRIAR e INICIALIZAR os campos de result
  // result->distance
  // result->predecessor

  result->distance = (int*)malloc(numVertices * sizeof(int));
  result->predecessor = (int*)malloc(numVertices * sizeof(int));
 
  for(int i = 0; i < numVertices; i++) result->distance[i] = INT_MAX / 2;
  
  result->distance[startVertex] = 0;

  result->graph = g;
  result->startVertex = startVertex;

  // EXECUTAR O ALGORITMO

  PriorityQueue* priorityqueue = PriorityQueueCreate(numVertices,comparator,printer);
  ITEM items[numVertices];

  for(int i = 0; i < numVertices; i++) {

    items[i].id = i;
    items[i].pri = result->distance[i];

    PriorityQueueInsert(priorityqueue,&items[i]);
  }
  while(!PriorityQueueIsEmpty(priorityqueue)){

    ITEM item = *(ITEM*)PriorityQueueGetMin(priorityqueue);

    unsigned int* adjacents = GraphGetAdjacentsTo(result->graph,item.id);
    int* distAdjacents = GraphGetDistancesToAdjacents(result->graph,item.id);
	  
    for(int i = 0; i < adjacents[0] + 1; i++) {

      if(result->distance[adjacents[i]] > result->distance[item.id] + distAdjacents[i]) {

        result->distance[adjacents[i]] = result->distance[item.id] + distAdjacents[i];
        items[adjacents[i]].pri = result->distance[adjacents[i]];
        result->predecessor[adjacents[i]] = item.id;
      }
    }

    PriorityQueueRemoveMin(priorityqueue);
  }

  return result;
}

void GraphDijkstraDestroy(GraphDijkstra** p) {
  assert(*p != NULL);

  GraphDijkstra* aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphDijkstraHasPathTo(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphDijkstraDistanceTo(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack* GraphDijkstraPathTo(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->distance[v] == INT_MAX) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphDijkstraShowPath(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphDijkstraPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphDijkstraDisplay(const GraphDijkstra* p) {

  for(int i = 0; i < GraphGetNumVertices(p->graph); i++) GraphDijkstraShowPath(p,i);
}

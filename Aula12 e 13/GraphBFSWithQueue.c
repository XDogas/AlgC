//
// Joaquim Madeira, AlgC, May 2020
// João Manuel Rodrigues, AlgC, May 2020
//
// GraphBFS - QUEUE-based Breadth-First Search
//

#include "GraphBFSWithQueue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersQueue.h"
#include "IntegersStack.h"

struct _GraphBFSWithQueue {
  unsigned int* marked;
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

GraphBFSWithQueue* GraphBFSWithQueueExecute(Graph* g,
                                            unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphBFSWithQueue* traversal =
      (GraphBFSWithQueue*)malloc(sizeof(struct _GraphBFSWithQueue));
  assert(traversal != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  // CRIAR e INICIALIZAR os campos de traversal
  // traversal->marked
  // traversal->distance
  // traversal->predecessor
  
  traversal->marked = (unsigned int*)calloc(numVertices,sizeof(unsigned int));
  traversal->distance = (int*)malloc(numVertices * sizeof(int));
  traversal->predecessor = (int*)malloc(numVertices * sizeof(int));

  assert(traversal->marked != NULL);  
  assert(traversal->distance != NULL);
  assert(traversal->predecessor != NULL);

  for (int i = 0; i < numVertices; i++) traversal->predecessor[i] = -1;
  for (int i = 0; i < numVertices; i++) traversal->distance[i] = numVertices + 1;  
  traversal->predecessor[startVertex] = 0;
  
  traversal->graph = g;
  traversal->startVertex = startVertex;

  // EFETUAR A TRAVESSIA

  Queue* queue = QueueCreate(numVertices);
  QueueEnqueue(queue,startVertex);
  
  traversal->marked[startVertex] = 1;
  
  while(!QueueIsEmpty(queue)){

    startVertex = QueueDequeue(queue);
    unsigned int* adjacents = GraphGetAdjacentsTo(g,startVertex);

    for(int i = 0; i < sizeof(adjacents) / sizeof(int); i++) {

      if(!traversal->marked[adjacents[i]]){

        traversal->predecessor[adjacents[i]] = startVertex;
        QueueEnqueue(queue,adjacents[i]);
        traversal->marked[adjacents[i]] = 1;
      }
    }
  }

  return traversal;
}

void GraphBFSWithQueueDestroy(GraphBFSWithQueue** p) {
  assert(*p != NULL);

  GraphBFSWithQueue* aux = *p;

  free(aux->marked);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphBFSWithQueueHasPathTo(const GraphBFSWithQueue* p,
                                        unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphBFSWithQueuePathTo(const GraphBFSWithQueue* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->marked[v] == 0) {
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

void GraphBFSWithQueueShowPath(const GraphBFSWithQueue* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphBFSWithQueuePathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphBFSWithQueueDisplay(const GraphBFSWithQueue* p) {

  for (int i = 0; i < GraphGetNumVertices(p->graph); i++) GraphBFSWithQueueShowPath(p,i);
}

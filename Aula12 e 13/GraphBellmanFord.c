//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphBellmanFord - Bellman-Ford Alg. for the Shortest Paths Tree
//

#include "GraphBellmanFord.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphBellmanFord {
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

GraphBellmanFord* GraphBellmanFordExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphBellmanFord* bellmanFord =
      (GraphBellmanFord*)malloc(sizeof(struct _GraphBellmanFord));
  assert(bellmanFord != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  // CRIAR e INICIALIZAR os campos de bellmanFord
  // bellmanFord->distance
  // bellmanFord->predecessor

  bellmanFord->distance = (int*)malloc(numVertices * sizeof(int));
  bellmanFord->predecessor = (int*)malloc(numVertices * sizeof(int));

  for (int i = 0; i < numVertices; i++) bellmanFord->distance[i] = INT_MAX / 2;

  bellmanFord->distance[startVertex] = 0;

  bellmanFord->graph = g;
  bellmanFord->startVertex = startVertex;

  // EXECUTAR O ALGORITMO

  for (int i = 0; i < numVertices; i++) {

	  for (int j = 0; j < numVertices; j++) {

      unsigned int* adjacents = GraphGetAdjacentsTo(g,j);
      int* weights = GraphGetDistancesToAdjacents(g,j);

      for (int k = 1; k < adjacents[0] + 1; k++) {

			  if(bellmanFord->distance[j] + weights[k] < bellmanFord->distance[adjacents[k]]) {

        bellmanFord->distance[adjacents[k]] = bellmanFord->distance[j] + weights[k];
        bellmanFord->predecessor[adjacents[k]] = j;
			  }
		  }
    }
  }

  return bellmanFord;
}

void GraphBellmanFordDestroy(GraphBellmanFord** p) {
  assert(*p != NULL);

  GraphBellmanFord* aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphBellmanFordHasPathTo(const GraphBellmanFord* p,
                                       unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphBellmanFordDistanceTo(const GraphBellmanFord* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack* GraphBellmanFordPathTo(const GraphBellmanFord* p, unsigned int v) {
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

void GraphBellmanFordShowPath(const GraphBellmanFord* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphBellmanFordPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphBellmanFordDisplay(const GraphBellmanFord* p) {
  
  for (int i = 0; i < GraphGetNumVertices(p->graph); i++) GraphBellmanFordShowPath(p,i);
}

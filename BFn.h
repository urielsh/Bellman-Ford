#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct Vertex
{
	char* name;
	char* pi;
	int   d;

}Vertex;

typedef struct Edge{
	Vertex* src;
	Vertex* dst;
	int   w;
}Edge;

typedef struct Graph{
	Vertex** vertices;
	Edge** edges;
	int verNum;
	int edgeNum;
}Graph;

void initGraph(Graph *graph);

/*The function creates the vertices by the data gatherd from a file input at argv[1] */
int readData(char* path, Graph *graph);

void createEdge(char *buffer, Graph *graph, int inputIndex);

/*The function verifies input as a unique vertex and adds it to the graph's vertices */
Vertex* addVertex(char *buffer, Vertex **vertices, int verNum);

void bellFord(Graph *graph,char *s);

void switchVerPointer(Vertex* v1,Vertex* v2);

void freeGraph(Graph*);

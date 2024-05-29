/*
 * BFn.c
 *
 *  Created on: Dec 11, 2014
 *      Author: uriel
 */

#include "BFn.h"

#define INFINITY 10000000
#define ERROR -1
#define DATA_LENGTH 150
#define MAX_ARGS 3
#define OK 1

const char GAP[2] = " ";

/* The function initializes graph's variables */
void initGraph(Graph *graph)
{
	graph->vertices = (Vertex**)malloc(sizeof(Vertex*) * graph->verNum);
	graph->edges = (Edge**)malloc(sizeof(Edge*));
	graph->edgeNum=0;
}

int readData(char* path, Graph *graph)
{
	int i = 0;
	char buffer[DATA_LENGTH];
	FILE *fp;

	fp=fopen(path,"r");
	if(fp==NULL)
	{
		printf("ERROR - Cannot communicate file input. ");
		return ERROR;
	}
	fgets(buffer,DATA_LENGTH,fp);
	graph->verNum = atoi(buffer);
	initGraph(graph);

	while(fgets(buffer,DATA_LENGTH,fp)!= NULL)  // Get all data from file, row by row.
	{
		graph->edges = (Edge**)realloc(graph->edges, sizeof(Edge*)*(++i));
		printf("\n edge num: [%d] \n",i );
		createEdge(buffer, graph, i-1);
	}
	return OK;
}


void createEdge(char *buffer, Graph *graph, int inputIndex)
{
	char* token;
	int i = 1;
	token = strtok(buffer, GAP);               // get first token in line
	graph->edges[inputIndex] = (Edge*)malloc(sizeof(Edge));

	for(i = 1 ; i <= MAX_ARGS ; i++)
	{
		switch(i)
		{
			case 1:
				graph->edges[inputIndex]->src = addVertex(token, graph->vertices, graph->verNum);
				break;
			case 2:
				graph->edges[inputIndex]->dst = addVertex(token, graph->vertices, graph->verNum);
				break;
			case 3:
				graph->edges[inputIndex]->w = atoi(token);
				break;
		}

		token = strtok(NULL, GAP);
		printf("\n token = %p \n" , token);
		if(token == NULL)
			break;
	}
	graph->edgeNum++;
}


Vertex* addVertex(char *buffer, Vertex **vertices, int verNum)
{
	int i;
	printf("In addVertex \n");
	for(i = 0; i < verNum ; i++)
	{
		if(vertices[i] != NULL && vertices[i]->name != NULL)
		{
			if(strcmp(buffer, vertices[i]->name)== 0)
			{
				return vertices[i];
			}
		}
		else
		{
			vertices[i] = (Vertex*)malloc(sizeof(Vertex));
			vertices[i]->name = malloc(sizeof(char)*strlen((buffer)));
			strcpy(vertices[i]->name, buffer);

			return vertices[i];
		}
	}
	return vertices[i];
}

void bellFord(Graph* graph,char* s)
{
	int i,j;
	// Initialize vertices for bellman-Ford Algorithm.
	for(i=0;i<graph->verNum;i++)
	{
		graph->vertices[i]->pi=NULL;
		graph->vertices[i]->d=INFINITY;

		if(strcmp(graph->vertices[i]->name,s)==0)
		{
			graph->vertices[i]->d=0;

			// Puts the source at the vertices array head.
			if(i!=0)
			switchVerPointer(graph->vertices[i],graph->vertices[0]);
		}
	}
	//Bellman Ford edges relax.
	for(i=0;i<graph->verNum;i++)
	{
		for(j=0;j<graph->edgeNum;j++)
		{
			if(graph->edges[j]->dst->d!=INFINITY && graph->edges[i]->src->d!=INFINITY)
				if(graph->edges[j]->dst->d < graph->edges[i]->src->d + graph->edges[j]->w)
				{
					graph->edges[j]->dst->d = graph->edges[j]->src->d + graph->edges[j]->w;
					graph->edges[j]->dst->pi=malloc(sizeof(graph->edges[j]->src->name)+1);
					strcpy(graph->edges[j]->dst->pi,graph->edges[j]->src->name);
				}
		}
	}
	//Check for an illegal negative cycle.
	for(j=0;j<graph->edgeNum;j++)
	{
		if(graph->edges[j]->dst->d < graph->edges[j]->src->d + graph->edges[j]->w)
		{
			printf("There is a negative cycle in the graph - the Bellman-Ford algorithm cannot be done well. ");
			exit(1);
		}
	}
	// Layout - dst via cost
	for(i=0;i<graph->verNum;i++)
	{
		printf(" %s %s %d ",graph->vertices[i]->name,graph->vertices[i]->pi,graph->vertices[i]->d);
	}
}

void switchVerPointer(Vertex* v1,Vertex* v2)
{
	Vertex* temp;
	temp=v2;
	v2=v1;
	v1=temp;
}

int main(int argc, char **argv)
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	int i;
	readData(argv[1], graph);
	//bellFord(graph,argv[2]);

	i = 0;
//	while(graph->edges[i] != NULL)
	for (i = 0 ; i < 8 ; i++)
	{
		printf("\n [src:(%s)] [dst:(%s)] [W:(%d)]",graph->edges[i]->src->name, graph->edges[i]->dst->name, graph->edges[i]->w);
	}

	return 0;
}




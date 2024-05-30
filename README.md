
# BF - Bellman-Ford Algorithm Implementation
This project implements the Bellman-Ford algorithm to find the shortest paths from a single source vertex to all other vertices in a weighted graph. The Bellman-Ford algorithm can handle graphs with negative edge weights and can detect negative cycles.
## Features
- **Graph Initialization**: Initialize graph data structures with vertices and edges.- **Data Reading**: Read graph data from a file and populate the graph structure.- **Edge Creation**: Create edges from the parsed data.- **Vertex Management**: Ensure vertices are unique and add them to the graph.- **Bellman-Ford Algorithm**: Compute shortest paths and detect negative cycles.- **Graph Management**: Utility functions for managing graph vertices and edges.
## Files
### 1. Project Configuration (`.project` file)
```xml<?xml version="1.0" encoding="UTF-8"?><projectDescription>    <name>BF</name>    <comment></comment>    <projects></projects>    <buildSpec>        <buildCommand>            <name>org.eclipse.cdt.managedbuilder.core.genmakebuilder</name>            <triggers>clean,full,incremental,</triggers>            <arguments></arguments>        </buildCommand>        <buildCommand>            <name>org.eclipse.cdt.managedbuilder.core.ScannerConfigBuilder</name>            <triggers>full,incremental,</triggers>            <arguments></arguments>        </buildCommand>    </buildSpec>    <natures>        <nature>org.eclipse.cdt.core.cnature</nature>        <nature>org.eclipse.cdt.managedbuilder.core.managedBuildNature</nature>        <nature>org.eclipse.cdt.managedbuilder.core.ScannerConfigNature</nature>    </natures></projectDescription>
### 2. Bellman-Ford Algorithm Implementation ('BFn.c')
/* * BFn.c * *  Created on: Dec 11, 2014 *      Author: uriel */#include "BFn.h"#define INFINITY 10000000#define ERROR -1#define DATA_LENGTH 150#define MAX_ARGS 3#define OK 1const char GAP[2] = " ";
// Function definitions...
### 3. Graph Structures and Prototypes ('BFn.h')
#include<stdio.h>#include<stdlib.h>#include<limits.h>#include<string.h>
typedef struct Vertex {    char* name;    char* pi;    int   d;} Vertex;
typedef struct Edge {    Vertex* src;    Vertex* dst;    int   w;} Edge;
typedef struct Graph {    Vertex** vertices;    Edge** edges;    int verNum;    int edgeNum;} Graph;void initGraph(Graph *graph);int readData(char* path, Graph *graph);void createEdge(char *buffer, Graph *graph, int inputIndex);Vertex* addVertex(char *buffer, Vertex **vertices, int verNum);void bellFord(Graph *graph, char *s);void switchVerPointer(Vertex* v1, Vertex* v2);void freeGraph(Graph*);### 4. Example Input File3 // number of router nodesRouter1 127.0.0.1 7000 // name, IP, PortRouter2 127.0.0.1 8000Router3 127.0.0.1 9000Router1 Router2 1 // route, distanceRouter1 Router3 2Router2 Router3 7### 5. How to Use- **Compile the Code**: Use an appropriate compiler for C code.- **Run the Program**: Execute the program with the input file as an argument.- **Observe the Output**: The program will output the shortest paths and detect any negative cycles.

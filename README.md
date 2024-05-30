
typedef struct Graph {
    Vertex** vertices;
    Edge** edges;
    int verNum;
    int edgeNum;
} Graph;

void initGraph(Graph *graph);
int readData(char* path, Graph *graph);
void createEdge(char *buffer, Graph *graph, int inputIndex);
Vertex* addVertex(char *buffer, Vertex **vertices, int verNum);
void bellFord(Graph *graph, char *s);
void switchVerPointer(Vertex* v1, Vertex* v2);
void freeGraph(Graph*);

### 4. Example Input File

3 // number of router nodes
Router1 127.0.0.1 7000 // name, IP, Port
Router2 127.0.0.1 8000
Router3 127.0.0.1 9000
Router1 Router2 1 // route, distance
Router1 Router3 2
Router2 Router3 7

### 5. How to Use
- **Compile the Code**: Use an appropriate compiler for C code.
- **Run the Program**: Execute the program with the input file as an argument.
- **Observe the Output**: The program will output the shortest paths and detect any negative cycles
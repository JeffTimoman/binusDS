#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge{
    int src, dest;
};

struct Graph{
    int V, E;
    struct Edge* edge;
};

Graph createGraph(int V, int E){
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edge = (struct Edge*) malloc(graph.E * sizeof(struct Edge));
    return graph;
}
int findParent(int *parent, int pos){
    if (parent[pos] == pos)
        return pos;
    return findParent(parent, parent[pos]);
}

bool isCycle(Graph graph){
    int parent[graph.V];

    for (int i = 0; i < graph.V; i++)
        parent[i] = i;

    for (int i = 0; i < graph.E; i++){
        int srcParent = findParent(parent, graph.edge[i].src);
        int destParent = findParent(parent, graph.edge[i].dest);

        if (srcParent == destParent)
            return true;

        //Union
        parent[srcParent] = destParent;
    }
}

int main(){
    return 0;
}
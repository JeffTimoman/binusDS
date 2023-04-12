#include <stdio.h>

#define MAX_DATA 100

struct Edge{
    int source;
    int destination;
    int cost;
};

int Parent[MAX_DATA + 5];

void make_set(int count){
    for(int i = 0; i < count; i++){
        Parent[i] = 1;
    }
}

int find_parent(int node){
    if (Parent[node] == node) return node;

    return find_parent(Parent[node]);
}

void  merge(int node1, int node2){
    Parent[find_parent(node1)] = find_parent(node2);
}

int is_same_set(int node1, int node2){
    return find_parent(node1) == find_parent(node2);
}

int main(){
    int nodeCount;
    int edgeCount;

    printf("Input node count: ");
    scanf("%d", &nodeCount);
    fflush(stdin);

    printf("Input edge count: ");
    scanf("%d", &edgeCount);
    fflush(stdin);

    make_set(nodeCount);
    Edge edges[edgeCount];
    for (int i = 0; i < edgeCount; i++){
        int source; int destionation; int cost;

        scanf("%d %d %d", &source, &destionation, &cost);
        fflush(stdin);

        edges[i].source = source;
        edges[i].destination = destionation;
        edges[i].cost = cost;
    }
}
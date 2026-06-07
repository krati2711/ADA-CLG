#include <stdio.h>

typedef struct{
    int src;
    int dest;
    int weight;
}Edge;

// find parent of a vertex
int find(int parent[], int i){
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

// join two sets
void Union(int parent[], int x, int y){
    parent[x]=y;
}

int main(){

    int V,E;

    printf("enter no of vertices:");
    scanf("%d",&V);

    printf("enter no of edges:");
    scanf("%d",&E);

    Edge edge[E];

    // input edges
    for(int i=0;i<E;i++){
        printf("enter src dest weight:");
        scanf("%d%d%d",
              &edge[i].src,
              &edge[i].dest,
              &edge[i].weight);
    }

    // sort edges by weight
    for(int i=0;i<E-1;i++){
        for(int j=i+1;j<E;j++){

            if(edge[i].weight > edge[j].weight){

                Edge temp=edge[i];
                edge[i]=edge[j];
                edge[j]=temp;
            }
        }
    }

    int parent[V];

    // initially every vertex is its own parent
    for(int i=0;i<V;i++)
        parent[i]=i;

    int count=0;
    int cost=0;

    printf("Edges in MST:\n");

    for(int i=0;i<E && count<V-1;i++){

        int x=find(parent,edge[i].src);
        int y=find(parent,edge[i].dest);

        if(x!=y){

            printf("%d - %d = %d\n",
                   edge[i].src,
                   edge[i].dest,
                   edge[i].weight);

            cost+=edge[i].weight;

            Union(parent,x,y);

            count++;
        }
    }

    printf("Total Cost = %d",cost);

    return 0;
}

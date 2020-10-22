#include<stdio.h>
#include<conio.h>
struct Graph
{
    int V;
    int E;
    int **adj;
};

struct Edge
{
    int u,v;
};

struct Graph *createGraph(int v,int e)
{
    int i,j;
    struct Graph *G;
    G=(struct Graph *)malloc(sizeof(struct Graph));
    G->V=v;
    G->E=e;
    G->adj=(int **)malloc(sizeof(int*)*G->V);
    for(i=0;i<G->V;i++)
    {
        G->adj[i]=(int *)malloc(sizeof(int)*G->V);
    }
    for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
        {
            G->adj[i][j]=0;
        }
        printf("\n");
    }

    return G;
}

void insert_Value(struct Edge e[],struct Graph *G)
{
    int i;
    for(i=0;i<7;i++)
    {
        G->adj[e[i].u - 1][e[i].v - 1]=1;
        G->adj[e[i].v - 1][e[i].u - 1]=1;
    }
};

void print_Value(struct Graph *G)
{
    int i,j;
    for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
        {
            printf("%d",G->adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Graph *G;
    G=createGraph(5,7);

    struct Edge e[7]={(1,2),(1,3),(2,3),(2,4),(3,4),(3,5),(4,5)};

    insert_Value(e,G);
    print_Value(G);
}

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct BFS
{
    int size;
    int **adjMat;
    int *visited;
}B;

void createBFS(int size)
{
    B.size = size;
    B.visited = (int*)malloc(B.size*sizeof(int));
    B.adjMat = (int**)malloc(B.size*sizeof(int));
    for(int i=0;i<B.size;i++) B.adjMat[i]= (int*)malloc(B.size*sizeof(int));
    for(int i=0;i<B.size;i++) B.visited[i]=0;
    for(int i=0;i<B.size;i++) for(int j=0;j<B.size;j++) B.adjMat[i][j]=0;
}

void add_edge(int a,int b){
    B.adjMat[a][b] = 1;
    B.adjMat[b][a] = 1;
}

void BreadthFirstSearch(int a){
    B.visited[a]=1;
    Enqueue(a);
    while(!isempty()){
        a=Front();
        Dequeue();
        printf("%d ",a);
        for(int i=0;i<B.size;i++){
            if(B.adjMat[a][i]==1 && B.visited[i]==0){
                B.visited[i]=1;
                Enqueue(i);
            }
        }
    }

}
    
int main(){
    int n,e;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);
    B.size = n;
    createBFS(B.size);
    for(int i=0;i<B.size;i++){
        printf("Enter the number of Edges for %d vertex : ",i);
        scanf("%d",&e);
        int *a = (int*)malloc(e*sizeof(int));
        printf("Enter edges : ");
        for(int j=0;j<e;j++){                
            scanf("%d",&a[j]); 
            add_edge(i,a[j]);               
        }
    }
    BreadthFirstSearch(0);
    return 0;
}

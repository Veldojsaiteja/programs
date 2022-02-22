#include<stdio.h>
#include<stdlib.h>

struct DFS
{
    int size;
    int **adjMat;
    int *visited;
}D;

void createDFS(int size)
{
    D.size = size;
    D.visited = (int*)malloc(D.size*sizeof(int));
    D.adjMat = (int**)malloc(D.size*sizeof(int));
    for(int i=0;i<D.size;i++) D.adjMat[i]= (int*)malloc(D.size*sizeof(int));
    for(int i=0;i<D.size;i++) D.visited[i]=0;
    for(int i=0;i<D.size;i++) for(int j=0;j<D.size;j++) D.adjMat[i][j]=0;
}

void add_edge(int a,int b){
    D.adjMat[a][b] = 1;
    D.adjMat[b][a] = 1;
}
    
void depthFirstSearch(int a){
    D.visited[a]=1;
    printf("%d ",a);
    for(int i=0;i<D.size;i++){
        if(D.adjMat[a][i]==1 && D.visited[i]==0){
           depthFirstSearch(i);
        }
    }
}

int main(){
    int n,e;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);
    D.size = n;
    createDFS(D.size);
    for(int i=0;i<D.size;i++){
        printf("Enter the number of Edges for %d vertex : ",i);
        scanf("%d",&e);
        int *a = (int*)malloc(e*sizeof(int));
        printf("Enter edges : ");
        for(int j=0;j<e;j++){                
            scanf("%d",&a[j]); 
            add_edge(i,a[j]);               
        }
    }
    depthFirstSearch(0);
    return 0;
}

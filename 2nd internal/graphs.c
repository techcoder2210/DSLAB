#include<stdio.h>
#include<stdlib.h>
int a[50][50], n, visited[50];
int q[20], front = -1,rear = -1;
int s[20], top = -1;

void bfs(int v){
	int i, cur;
	visited[v] = 1;
	q[++rear] = v;
	while(front != rear){
		cur = q[++front];
		for(i=1;i<=n;i++){
			if((a[cur][i] == 1) && (visited[i] == 0)){
				q[++rear] = i;
				visited[i] = 1;
				printf("%d ", i);
			}
		}
	}
}

void dfs(int v)
{   int i;
    visited[v] = 1;
    s[++top] = v;
    for(i=1;i<=n;i++)
    {   if(a[v][i] == 1 && visited[i] == 0 )
        {   printf("%d ", i);
            dfs(i);
        }
    }
}


int main()
{   int ch, start, i,j;
    printf("no of cities: ");
    scanf("%d",&n);
    printf("adjacency matrix:\n");
    for(i=1; i<=n; i++)
    {   for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("starting city: ");
    scanf("%d",&start);
    printf("1. BFS");
    printf("\n2. DFS");
    printf("\n3: Exit");
    printf("\nChoice: ");
    scanf("%d", &ch);
    switch(ch)
    {   case 1: printf("Cities reachable from %d:\n",start);
    			bfs(start);
                break;
        case 2: printf("Cities reachable from %d:\n",start);
        		dfs(start);
                break;
        case 3: exit(0);
        default: printf("Invalid choice\n");
        }
}

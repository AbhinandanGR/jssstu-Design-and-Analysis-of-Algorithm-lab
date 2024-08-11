#include<iostream>
using namespace std;

void bfs(int cost[20][20], int source, int vis[20], int n){
	int queue[20], u;
	int front = 0;
	int rear = -1;
	int traversal[20], index = 0;
	
	queue[++rear] = source;
	vis[source] = 1;
	while(front <= rear){
		u = queue[front++];
		traversal[index++] = u;
		for(int v = 1; v <= n; v++){
			if(cost[u][v] == 1 && vis[v] == 0){
				queue[++rear] = v;
				vis[v] = 1;
			}
		}
	}
	
	cout << "BFS traversal : " << endl;
	for(int i = 0; i < index; i++)
		cout << traversal[i] << " ";
	cout << endl;	
}

int main(){
	int n, cost[20][20], vis[20], source;
	cout << "Enter the number of vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (1 for edge and 0 for no-edge) : " << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> cost[i][j];
	
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	
	cout << "Enter the source node : ";
	cin >> source;
	
	if(source < 1 || source > n){
		cout << "Source node should be between 1 and " << n << endl;
		return 1;
	}
	
	bfs(cost, source, vis, n);
	
	for(int i = 1; i <= n; i++){
		if(vis[i] != 0)
			cout << "Node " << i << " is reachable " << endl;
		else
			cout << "Node " << i << "is not reachable " << endl;		
	}
	cout << endl;
	
	return 0;
}

/*

output

Enter the number of vertices : 4
Enter the cost matrix (1 for edge and 0 for no-edge) : 
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
Enter the source node : 1
BFS traversal : 
1 2 3 4 
Node 1 is reachable 
Node 2 is reachable 
Node 3 is reachable 
Node 4 is reachable 


Enter the number of vertices : 5
Enter the cost matrix (1 for edge and 0 for no-edge) : 
0 1 0 1 0
1 0 1 1 0
0 1 0 0 1
1 1 0 0 1
0 0 1 1 0
Enter the source node : 3
BFS traversal : 
3 2 5 1 4 
Node 1 is reachable 
Node 2 is reachable 
Node 3 is reachable 
Node 4 is reachable 
Node 5 is reachable 



*/



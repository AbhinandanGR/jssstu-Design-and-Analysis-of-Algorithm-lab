#include<iostream>
using namespace std;

void dij(int cost[10][10], int source, int n, int vis[10], int dis[10]){
	int min, u;
	
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		dis[i] = cost[source][i];
	}	
	vis[source] = 1;
	dis[source] = 0;
	
	for(int i = 2; i <= n; i++){
		min = 999;
		for(int j = 1; j <= n; j++){
			if(!vis[j]){
				if(dis[j] < min){
					min = dis[j];
					u = j;
				}
			}
		}
		
		vis[u] = 1;
		for(int v = 1; v <= n; v++){
			if(cost[u][v] != 999 && vis[v] == 0){
				if(dis[v] > dis[u]+cost[u][v])
					dis[v] = dis[u]+cost[u][v];
			}
		}
	}	
}

int main(){
	
	int source, cost[10][10], n, vis[10], dis[10];
	
	cout << "Enter the no. of vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (0 for self loop & 999 for no edge) : " << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> cost[i][j];
			
	cout << "Enter the source : ";
	cin >> source;
	
	dij(cost, source, n, vis, dis);
	
	for(int i = 1; i <= n; i++){
		if(i != source)
			cout << "\nShortest path from " << source << " --> " << i << " is " << dis[i];
	}
	
	cout << endl;	
	
	return 0;
}

/*

output

Output:-
Enter the No. of vertices :5
Enter the cost matrix (0 for self loop & 999 for no edge) 
0 6 999 1 999
6 0 5 2 2
999 5 0 999 5
1 2 999 0 1
999 2 5 1 0
Enter the source :1

Shortest path from 1 --> 2 is 3
Shortest path from 1 --> 3 is 7
Shortest path from 1 --> 4 is 1
Shortest path from 1 --> 5 is 2

*/



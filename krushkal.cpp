#include<iostream>
using namespace std;
#define max 10

int find(int parent[], int i){
	while(parent[i] > 0)
		i = parent[i];
	return i;
}

void Union(int parent[], int i, int j){
	parent[j] = i;
}

void kruskal(int cost[max][max], int n){
	int parent[max];
	for(int i = 1; i <= n; i++)
		parent[i] = -1;
	
	int a = 0, b = 0, u = 0, v = 0;
	int i, j, min, minCost = 0;
	int ne = 1;
	
	while(ne < n){
		for(i = 1, min = 999; i <= n; i++){
			for(j = 1; j<= n; j++){
				if(cost[i][j] < min){
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		
		u = find(parent, u);
		v = find(parent, v);		
		if(u != v){
			Union(parent, u, v);
			cout << "Edge - " << ne++ << " (" << a << ", " << b <<") : "<< min << endl;
			minCost += min;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	cout << "Minimum cost is : " << minCost;	
}

int main(){
	
	int n, cost[max][max];
	
	cout << "Enter the no. vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (999 for no edge and self loop) : " << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> cost[i][j];
	
	kruskal(cost, n);
	cout << endl;
	
	return 0;
}


/*
output

Enter the no. vertices : 4
Enter the cost matrix (999 for no edge and self loop) : 
999 10  6  5
10  999  15  4
6  15  999  8
5  4  8  999
Edge - 1 (2, 4) : 4
Edge - 2 (1, 4) : 5
Edge - 3 (1, 3) : 6
Minimum cost is : 15


*/



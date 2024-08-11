#include<iostream>
using namespace std;
#define max 10

void prims(int cost[max][max], int n){
	int a = 0, b = 0, u = 0, v = 0;
	int i, j, min, minCost = 0;
	int ne = 1;
	int vis[max] = {0};
	vis[1] = 1;
	
	while(ne < n){
		for(i = 1, min = 999; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(cost[i][j] < min){
					if(vis[i] != 0){
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
				}
			}
		}
		
		if(vis[u] == 0 || vis[v] == 0){
			cout << "Edges - " << ne++ << " (" << a << ", " << b << " ) : " << min << endl;
			minCost += min;
			vis[b] = 1;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	cout << "Minimum cost is : " << minCost;
}

int main(){
	int n, cost[max][max];
	
	cout << "Enter the no. of vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (999 for no-edge and self loops) : " << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j<= n; j++)
			cin >> cost[i][j];
	
	prims(cost, n);
	cout << endl;
	
	return 0;
}


/*

output

Enter the no. of vertices : 4
Enter the cost matrix (999 for no-edge and self loops) : 
999 10  6  5
10  999  15  4
6  15  999  8
5  4  8  999
Edges - 1 (1, 4 ) : 5
Edges - 2 (4, 2 ) : 4
Edges - 3 (1, 3 ) : 6
Minimum cost is : 15


*/


#include<iostream>
using namespace std;

void dfs(int source, int n, int cost[20][20], int vis[20], int &count){
	vis[source] = 1;
	count++;
	
	for(int i = 1; i <= n; i++)
		if(vis[i] == 0 && cost[source][i] == 1)
			dfs(i, n, cost, vis, count);	
}

int main(){
	int n, source, cost[20][20], vis[20], count = 0;
	
	cout << "Enter the no. vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (1 for edge and 0 for no-edge) : " <<endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> cost[i][j];
			
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	
	cout << "Enter the source vertices : ";
	cin >> source;
	
	if(source < 1 || source > n){
		cout << "Soure node should be between 1 and " << n << endl;
		return 1;
	}
	
	dfs(source, n, cost, vis, count);
	
	if(count == n)
		cout << "The graph is connected " << endl;
	else
		cout << "The graph is not connected " << endl;
	

	return 0;
}

/*
output

Enter the no. vertices : 4
Enter the cost matrix (1 for edge and 0 for no-edge) : 
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0 
Enter the source vertices : 1
The graph is connected 


Enter the no. vertices : 5
Enter the cost matrix (1 for edge and 0 for no-edge) : 
0 1 1 0 0 
1 0 1 0 0
1 1 0 0 0 
0 0 0 0 1
0 0 0 1 0 
Enter the source vertices : 1
The graph is not connected 


*/



#include<iostream>
using namespace std;
#define max 10

void warshall(int cost[max][max], int n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cost[i][j] = cost[i][j] || (cost[i][k] && cost[k][j]);
		}
	}
}

void print(int cost[max][max], int n){
	cout << "After applying Warshall's Transitive Closure : " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << cost[i][j] << " ";
		cout << endl;			
	}
	cout << endl;
}

int main(){
	
	int n, cost[max][max];
	
	cout << "Enter the no. of vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (1 for edge and 0 for no edge) : " << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> cost[i][j];
		
	warshall(cost, n);
	print(cost, n);
	
	return 0;
}

/*
output

Enter the no. of vertices : 4
Enter the cost matrix (1 for edge and 0 for no edge) : 
0 1 0 0
0 0 1 0
1 0 0 1
0 0 0 0
After applying Warshall's Transitive Closure : 
1 1 1 1 
1 1 1 1 
1 1 1 1 
0 0 0 0 


*/


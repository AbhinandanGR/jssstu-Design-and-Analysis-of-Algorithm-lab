#include<iostream>
using namespace std;
#define max 10
#define INF 999

int mini(int a, int b){
	return (a < b) ? a : b;
}

void floyd(int cost[max][max], int n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cost[i][j] = mini(cost[i][j], (cost[i][k]+cost[k][j]));
			}
		}
	}
}

void print(int cost[max][max], int n){
	cout << "After applying Floyd's Algorithm : " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(cost[i][j] == INF)
				cout << "INF ";
			else 
				cout << cost[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int n, cost[max][max];
	
	cout << "Enter the no. of vertices : ";
	cin >> n;
	
	cout << "Enter the cost matrix (999 for inifinty) : " << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> cost[i][j];
		
	floyd(cost, n);
	print(cost, n);
	
	return 0;
}


/*
output

Enter the no. of vertices : 4
Enter the cost matrix (999 for inifinty) : 
0 3 999 7
999 0 1 999
999 999 0 2
999 999 999 0
After applying Floyd's Algorithm : 
0 3 4 6 
INF 0 1 3 
INF INF 0 2 
INF INF INF 0 


Enter the no. of vertices : 3
Enter the cost matrix (999 for inifinty) : 
0 1 999
999 0 1
999 999 0
After applying Floyd's Algorithm : 
0 1 2 
INF 0 1 
INF INF 0 


*/


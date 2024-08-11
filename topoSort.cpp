#include<iostream>
using namespace std;
#define max 10

void find_indegree(int cost[max][max], int indegree[max], int n){
	int sum;
	for(int i = 1; i <= n; i++){
		sum = 0;
		for(int j = 1; j <= n; j++)
			sum += cost[j][i];
		indegree[i] = sum;
	}	
}

void topo_sort(int cost[max][max], int n){
	int indegree[max], stack[max], topo[max];
	int top = -1, k = 0, count = 0;
	
	find_indegree(cost, indegree, n);
	
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0)
			stack[++top] = i;
	}
	
	while(top != -1){
		int u = stack[top--];
		topo[k++] = u;
		count++;
		
		for(int v = 1; v <= n; v++){
			if(cost[u][v] == 1){
				indegree[v]--;
				if(indegree[v] == 0)
					stack[++top] = v;
			}
		}
	}
	
	if(count != n)
		cout << "Graph contains cycle ";
	else{
		cout << "Topological ordering : " << endl;
		for(int i = 0; i < n; i++)
			cout << topo[i] << " ";
	}
	cout << endl;
}

int main(){
	
	int n, cost[max][max];
	
	cout << "Enter the no. nodes : ";
	cin >> n;
	
	cout << "Enter the cost matrix (1 for edge & 0 no-edge) : " << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> cost[i][j];
			
	topo_sort(cost, n);
	
	return 0;
}

/*

output

Enter the cost matrix (1 for edge & 0 no-edge) : 
0 1 0 1 0
0 0 0 1 1
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
Topological ordering : 
1 2 5 4 3 


*/



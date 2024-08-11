#include<iostream>
using namespace std;

void swap(int v[], int i, int j){
	int t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void TSP(int v[], int n, int i, int c[100][100], int s, float &optimum){
	int sum = 0;
	if(i == n){
		if(v[0] == s){
			sum = 0;
			for(int k = 0; k < n-1; k++)
				sum += c[v[k]][v[k+1]];
			sum += c[v[n-1]][s];
			if(sum < optimum)
				optimum = sum;
		}
	}
	else{
		for(int j = i; j < n; j++){
			swap(v, i, j);
			TSP(v, n, i+1, c, s, optimum);
			swap(v, i, j);
		}
	}
}

void approx(int n, int c[100][100], int s, float &sum){
	int min, p, vis[20], from;
	
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	
	vis[s] = 1;
	from = s;
	sum = 0;
	
	for(int i = 1; i < n; i++){
		min = 999;
		for(int j = 1; j <= n; j++){
			if(vis[j] != 1 && c[from][j] < min && c[from][j] != 0){
				min = c[from][j];
				p = j;
			}
		}
		vis[p] = 1;
		from = p;
		sum += min;
	}
	sum += c[from][s];	
}

int main(){
	int v[100], n, c[100][100], s;
	float optimum = 999, sum;
	
	cout << "Enter the No. of vertices : ";
	cin >> n;
	
	for(int i = 0; i < n; i++)
		v[i] = i+1;
	
	cout << "Enter the cost matrix (999 for infinity)" << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> c[i][j];
			
	cout << "Enter the source : ";
	cin >> s;
	
	if(s < 1 || s > n){
		cout << "Error: SOurce vertex must be between 1 and " << n << endl;
		return 1;
	}
	
	TSP(v, n, 0, c, s, optimum);
	cout << "Optimum solution is " << optimum << endl;
	
	approx(n, c, s, sum);
	cout << "Solution with approximation algorithm is " << sum << endl;
	
	cout << "Approximation val is " << ((sum/optimum)-1)*100 << "%" << endl;
	
	return 0;
}

/*

Enter the No. of vertices : 4
Enter the cost matrix (999 for infinity)
0  10  15  20
10  0  35  25
15  35  0  30
20  25  30  0
Enter the source : 1
Optimum solution is 80
Solution with approximation algorithm is 80
Approximation val is 0%


Enter the No. of vertices : 4
Enter the cost matrix (999 for infinity)
0  2  9  10
1  0  6  4
15  7  0  8
6  3  12  0
Enter the source : 1
Optimum solution is 21
Solution with approximation algorithm is 33
Approximation val is 57.1429%


*/



#include<iostream>
using namespace std;
#define MAX 10

void print(int board[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i] == j)
				cout << " Q ";
			else
				cout << " - ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(int board[], int row, int col){
	for(int i = 0; i < row; i++){
		if(board[i] == col || (board[i]-col) == (i-row) || (board[i] - col) == (row-i))
			return false;
	}
	return true;
}

void nqueen(int board[], int row, int n){
	if(row == n){
		print(board, n);
		return;
	}	
	
	for(int col = 0; col < n; col++){
		if(isSafe(board, row, col)){
			board[row] = col;
			nqueen(board, row+1, n);
		}
	}
	
}

int main(){
	
	int n;
	int board[MAX];
	
	cout << "Enter the no. of Queen's : ";
	cin >> n;
	
	nqueen(board, 0, n);
	
	return 0;
}

/*

output

Enter the no. of Queen's : 4
 -  Q  -  - 
 -  -  -  Q 
 Q  -  -  - 
 -  -  Q  - 

 -  -  Q  - 
 Q  -  -  - 
 -  -  -  Q 
 -  Q  -  - 


*/



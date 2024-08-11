#include<iostream>
using namespace std;
#define max 100

int maxi(int a, int b){
	return (a>b)? a : b;
}

int knapsack(int capacity, int item, int weight[], int profit[], int knap[max][max]){
	for(int i = 0; i <= item; i++){
		for(int j = 0; j <= capacity; j++){
			if(i == 0 || j == 0)
				knap[i][j] = 0;
			else if(weight[i-1] <= j)
				knap[i][j] = maxi(profit[i-1] + knap[i-1][j-weight[i-1]], knap[i-1][j]);
			else
				knap[i][j] = knap[i-1][j];		
		}
	}
	return knap[item][capacity];
}

int main(){
	
	int capacity, item, profit[max], weight[max], optimum_val;
	
	cout << "Enter the no. of objects : ";
	cin >> item;
	
	cout << "Enter the weights : "; 
	for(int i = 0; i < item; i++)
		cin >> weight[i];
	
	cout << "Enter the profit : ";
	for(int i = 0; i < item; i++)
		cin >> profit[i];
		
	cout << "Enter the Knapsack Capacity : ";
	cin >> capacity;
	
	int knap[max][max];
	optimum_val = knapsack(capacity, item, weight, profit, knap);
	
	cout << "\nProfit table\n";
	for(int i = 0; i <= item; i++){
		for(int j = 0; j <= capacity; j++){
			cout << knap[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << "The maximum profit is : " << optimum_val << endl;
	
	return 0;
}

/*

output 

Enter the no. of objects : 5
Enter the weights : 3 4 5 6 7 
Enter the profit : 50 40 10 30 20
Enter the Knapsack Capacity : 10

Profit table
0	0	0	0	0	0	0	0	0	0	0	
0	0	0	50	50	50	50	50	50	50	50	
0	0	0	50	50	50	50	90	90	90	90	
0	0	0	50	50	50	50	90	90	90	90	
0	0	0	50	50	50	50	90	90	90	90	
0	0	0	50	50	50	50	90	90	90	90	
The maximum profit is : 90


Enter the no. of objects : 4
Enter the weights : 1 3 4 5
Enter the profit : 10 40 50 70
Enter the Knapsack Capacity : 7

Profit table
0	0	0	0	0	0	0	0	
0	10	10	10	10	10	10	10	
0	10	10	40	50	50	50	50	
0	10	10	40	50	60	60	90	
0	10	10	40	50	70	80	90	
The maximum profit is : 90



*/



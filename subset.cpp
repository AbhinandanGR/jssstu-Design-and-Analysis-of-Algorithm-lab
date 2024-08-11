#include<iostream>
using namespace std;
#define max 100

void display(int set[], int count){
	cout << "{";
	for(int i = 0; i < count; i++)
		cout << " " << set[i] << " ";
	cout << "}" << endl;
}

void subset(int s[], int set[], int n, int d, int sum, int i, int count, bool &flag){
	if(sum == d){
		flag = true;
		display(set, count);
		return;
	}
	
	if(sum > d || i >= n)
		return;
	
	set[count] = s[i];
	subset(s, set, n, d, sum+s[i], i+1, count+1, flag);
	subset(s, set, n, d, sum, i+1, count, flag);	
}

int main(){
	int n, s[max], set[max];
	
	cout << "Enter the no. of elements : ";
	cin >> n;
	
	cout << "Enter the values : ";
	for(int i = 0; i < n; i++)
		cin >> s[i];
	
	int d;
	cout << "Enter the sum : ";
	cin >> d;
	
	bool flag = false;
	cout << "Solution" << endl;
	
	subset(s, set, n, d, 0, 0, 0, flag);
	
	if(!flag)
		cout << "There is no solution" << endl; 
	
	return 0;
}

/*
output

Enter the no. of elements : 5
Enter the values : 1 2 5 6 8
Enter the sum : 9
Solution
{ 1  2  6 }
{ 1  8 }


Enter the no. of elements : 4
Enter the values : 7 5 3 2
Enter the sum : 20
Solution
There is no solution


*/



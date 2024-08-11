#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low;
	int j = high;
	
	while(i < j){
		while(arr[i] <= pivot && i < high)
			i++;
		while(arr[j] > pivot && j > low)
			j--;
		if(i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]);
	return j;
	
}

void quickSort(int arr[], int low, int high){
	if(low >= high)
		return;
	int p = partition(arr, low, high);
	quickSort(arr, low, p-1);
	quickSort(arr, p+1, high);
}

int main(){
	
	int arr[100000];
	int n;
	
	cout << "Enter the number of elements to be sorted : ";
	cin >> n;
	cout << "The Random numbers are : ";
	for(int i = 0; i < n; i++){
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	} 
	cout << endl;
	
	clock_t start = clock();
	quickSort(arr, 0, n-1);
	clock_t end = clock();
	
	cout << "Sorted Elements are : ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	double time = (double)(end-start)/CLOCKS_PER_SEC;
	cout << "Time taken for sorting " << n << "elements is : " << time << endl;
	
	ofstream file;
	file.open("quicksort.txt", ofstream :: app);
	
	for(int i = 10000; i < 100000; i+=2000){
		n = i;
		int arr[n];
		
		for(int i = 0; i < n; i++)
			arr[i] = rand()%100;
		
		clock_t start = clock();
		quickSort(arr, 0, n-1);
		clock_t end = clock();
		
		double t = (double)(end - start)/CLOCKS_PER_SEC;
		
		file << n << "\t" << t << endl;		
	}
	
	file.close();
	cout << "Time to sort 10000 to 10000 (incrementing 2000 per iteration) element is added to the file quicksort.txt" << endl;
	
	return 0;
}


/*

Taking the input from file

int main() {
    int n, i, j;
    ifstream infile("input.txt");

    if (!infile) {
        cout << "Unable to open file";
        return 1; // return with error code
    }

    infile >> n;
    int a[n];

    cout << "The elements read from file are: ";
    for (i = 0; i < n; i++) {
        infile >> a[i];
        cout << a[i] << " ";
    }
    infile.close();

    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t end = clock();

    cout << "\nSorted Elements are: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken to sort " << n << " elements is: " << time;

    return 0;
}

*/



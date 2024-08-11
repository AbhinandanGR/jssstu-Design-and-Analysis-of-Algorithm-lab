#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

void merge(int arr[], int start, int end, int mid){
	int len1 = mid-start+1;
	int len2 = end-mid;
	
	int *first = new int[len1];
	int *second = new int[len2];
	
	int k = start;
	for(int i = 0; i < len1; i++)
		first[i] = arr[k++];
	
	k = mid+1;
	for(int i = 0; i < len2; i++)
		second[i] = arr[k++];
	
	int index1 = 0;
	int index2 = 0;
	k = start;
	while(index1 < len1 && index2 < len2){
		if(first[index1] < second[index2])
			arr[k++] = first[index1++];
		else
			arr[k++] = second[index2++];
	}
	while(index1 < len1)
		arr[k++] = first[index1++]; 
	while(index2 < len2)
		arr[k++] = second[index2++];
	
	delete []first;
	delete []second;
}

void mergeSort(int arr[], int start, int end){
	if(start >= end)
		return;
	int mid = (start + end)/2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, start, end, mid);
}

int main(){
	
	int n, arr[10000];
	cout << "Enter the number of elements to be sorted : ";
	cin >> n;
	
	cout << "Random numbers are : ";
	for(int i = 0; i < n; i++){
		arr[i] = rand()%100;
		cout << arr[i] << " ";
	}
	cout << endl;
	
	clock_t start = clock();
	mergeSort(arr, 0, n-1);
	clock_t end = clock();
	
	cout << "Sorted Elements are : ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	double time = (double)(end-start)/CLOCKS_PER_SEC;
	cout << "Time taken for sorting " << n << " elements is : " << time << endl;
	
	ofstream file;
	file.open("mergesort.txt", ofstream :: app);
	
	for(int i = 10000; i < 100000; i+= 2000){
		n = i;
		int arr[n];
		
		for(int i = 0; i < n; i++)
			arr[i] = rand()%100;
		
		clock_t start = clock();
		mergeSort(arr, 0, n-1);
		clock_t end = clock();
		
		double t = (double) (end-start)/CLOCKS_PER_SEC;
		file << n << "\t" << t << endl;		
	}
	
	file.close();
	cout << "Time to sort 10000 to 100000 (incrementing 2000 per iteration) element is added to the file mergesort.txt" << endl;
		
		
	return 0;
}

/*

//Taking the input from file

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
    mergeSort(a, 0, n - 1);
    clock_t end = clock();

    cout << "\nSorted Elements are: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken to sort " << n << " elements is: " << time;

    return 0;
}

*/



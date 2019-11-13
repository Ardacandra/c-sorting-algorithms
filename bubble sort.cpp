#include <iostream>
using namespace std;

void swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print (int arr[], int n){
	for (int i = 0; i< n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubble_ascending (int arr[] , int n){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-1-i;j++){
			if (arr[j] > arr[j+1])
				swap (&arr[j], &arr[j+1]);			
		}
	}
}

void bubble_descending (int arr[] , int n){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-1-i;j++){
			if (arr[j] < arr[j+1])
				swap (&arr[j], &arr[j+1]);			
		}
	}
}

int main () {
	int data[] ={10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72};
	int jumlah = sizeof(data)/sizeof(data[0]);
	
	bubble_ascending (data , jumlah);
	print (data , jumlah);
	
	bubble_descending (data, jumlah);
	print (data, jumlah);
	return 0;
}

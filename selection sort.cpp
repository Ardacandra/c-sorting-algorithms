#include <iostream>
using namespace std;

void swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print (int arr[], int n){
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void selection_ascending (int arr[], int n){
	for (int i = 0; i < n-1 ;i++){
		int min = i;
		for (int j = i+1; j < n; j++){
			if (arr[j] < arr[min])
				min = j;
		}
	swap(&arr[i] , &arr[min]);
	}	
}

void selection_descending (int arr[], int n){
	for (int i = 0; i < n-1 ;i++){
		int max = i;
		for (int j = i+1; j < n; j++){
			if (arr[j] > arr[max])
				max = j;
		}
	swap(&arr[i] , &arr[max]);
	}	
}

int main () {
	int data[] ={10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72};
	int jumlah = sizeof(data)/sizeof(data[0]);
	
	selection_ascending (data , jumlah);
	print (data , jumlah);
	
	selection_descending (data, jumlah);
	print (data, jumlah);
	return 0;
}

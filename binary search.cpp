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

void insertion_ascending (int arr[], int n){
	for (int i = 0; i < n-1; i++){
		int j ;
		int key = arr[i+1];
		for (j = i; key < arr[j] && j >= 0 ; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void binary_search (int arr[], int min, int max, int query){
		int mid = (min + max)/2;
		if (min <= max ){
			if(arr[mid] == query)
				cout << "Angka ditemukan pada urutan ke-" << mid + 1;
			if(arr[mid] > query)
				binary_search (arr, min, mid-1, query);
			if(arr[mid] < query)
				binary_search (arr, mid+1, max, query);		
		}
		else 
			cout << "Angka tidak ditemukan.";
		
}	


int main () {
	int data[] ={10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72};
	int jumlah = sizeof(data)/sizeof(data[0]);
	
	insertion_ascending (data , jumlah);
	print (data , jumlah);
	binary_search (data, 0, jumlah-1, 21);
	
	return 0;
}

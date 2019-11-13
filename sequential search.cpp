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

void sequential_search (int arr[], int n, int query){
	bool found = false;
	for (int i = 0; i < n && found == false ; i++){
		if (arr[i] == query){
			cout << "Angka berada pada urutan ke-"<< i+1;
			found = true;
		}
	}
	if (found == false)
		cout << "Angka tidak ditemukan.";
}


int main () {
	int data[] ={10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72};
	int jumlah = sizeof(data)/sizeof(data[0]);
	
	insertion_ascending (data , jumlah);
	print (data , jumlah);
	sequential_search (data, jumlah, 21);
	
	return 0;
}

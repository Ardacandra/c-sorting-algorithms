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

int partition_ascending(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quick_ascending(int arr[], int low, int high) 
{ 
    if (low < high) 
    {
        int pi = partition_ascending(arr, low, high); 
  
    
        quick_ascending(arr, low, pi - 1); 
        quick_ascending(arr, pi + 1, high); 
    } 
} 

int partition_descending(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] >= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quick_descending(int arr[], int low, int high) 
{ 
    if (low < high) 
    {
        int pi = partition_descending(arr, low, high); 
  
    
        quick_descending(arr, low, pi - 1); 
        quick_descending(arr, pi + 1, high); 
    } 
} 

int main () {
	int data[] ={10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72};
	int jumlah = sizeof(data)/sizeof(data[0]);
	
	quick_ascending (data , 0, jumlah-1);
	print (data , jumlah);
	
	quick_descending (data , 0, jumlah-1);
	print (data , jumlah);

	return 0;
}

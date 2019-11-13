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

void insertion_descending (int arr[], int n){
	for (int i = 0; i < n-1; i++){
		int j;
		int key = arr[i+1];
		for (j = i ; key > arr[j] && j >= 0 ; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void merge_up(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0;  
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_down(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0;  
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) { 
        if (L[i] >= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void merge_ascending(int arr[], int l, int r) { 
    if (l < r) {  
        int m = (l+r)/2; 
  
        merge_ascending(arr, l, m); 
        merge_ascending(arr, m + 1, r); 
  
        merge_up(arr, l, m, r); 
    } 
} 
  
void merge_descending(int arr[], int l, int r) { 
    if (l < r) {  
        int m = (l+r)/2; 
  
        merge_descending(arr, l, m); 
        merge_descending(arr, m + 1, r); 
  
        merge_down(arr, l, m, r); 
    } 
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

int main (){
	
int data[] ={10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72};
int jumlah = sizeof(data)/sizeof(data[0]);
int sort_menu , search_menu;

	cout << "Data : {10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,4,8,9,21,35,72} \nPilih menu : \n1.Bubble Sort \n2.Selection Sort \n3.Insertion Sort \n4.Merge Sort \n5.Quick Sort" << endl;
	cin >> sort_menu;
	if (sort_menu == 1){
		bubble_ascending (data , jumlah);
		print (data , jumlah);
	
		bubble_descending (data, jumlah);
		print (data, jumlah);
	}
	if (sort_menu == 2){
		selection_ascending (data , jumlah);
		print (data , jumlah);
	
		selection_descending (data, jumlah);
		print (data, jumlah);
	}
	if (sort_menu == 3){
		insertion_ascending (data , jumlah);
		print (data , jumlah);
	
		insertion_descending (data, jumlah);
		print (data, jumlah);
	}
	if (sort_menu == 4){
		merge_ascending (data, 0, jumlah-1);
		print (data , jumlah);
	
		merge_descending (data, 0, jumlah-1);
		print (data , jumlah);
	}
	if (sort_menu == 5){
		quick_ascending (data , 0, jumlah-1);
		print (data , jumlah);
	
		quick_descending (data , 0, jumlah-1);
		print (data , jumlah);
	}
	cout << "\nPilih metode search : \n1.Sequential Search \n2.Binary Search" << endl;
	cin >> search_menu;
	
	if (search_menu == 1){
		insertion_ascending (data , jumlah);
		print (data , jumlah);
		cout << "Mencari angka 11 :";
		sequential_search (data, jumlah, 11);
		cout << "\nMencari angka 21 :";
		sequential_search (data, jumlah, 21);
	}
	
	
	if (search_menu == 2){
		insertion_ascending (data , jumlah);
		print (data , jumlah);
		cout << "Mencari angka 11 :";
		binary_search (data, 0, jumlah-1, 11);
		cout << "\nMencari angka 21 :";
		binary_search (data, 0, jumlah-1, 21);

	}
	
	return 0;
}

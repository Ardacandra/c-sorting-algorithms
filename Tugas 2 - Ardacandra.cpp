#include <iostream>
using namespace std;

struct data {
	string NISN;
	string Nama;
	int Nilai;
};

void binary_search (data arr[], int min, int max, string query){
		int mid = (min + max)/2;
		if (min <= max ){
			if(arr[mid].NISN == query)
				cout << "\nNISN 9950310962 ditemukan pada urutan ke-" << mid + 1 << "\nNilai mahasiswa tersebut adalah " << arr[mid].Nilai << endl;
			if(arr[mid].NISN > query)
				binary_search (arr, min, mid-1, query);
			if(arr[mid].NISN < query)
				binary_search (arr, mid+1, max, query);		
		}
		else 
			cout << "\nNISN tidak ditemukan." << endl;;
		
}	

int main (){
	int i, j, menu_sort;
	data mahasiswa[7];
	data temp;
	temp.NISN = "";
	temp.Nama = "";
	temp.Nilai = 0;
	mahasiswa[0].NISN = "9960312699";
	mahasiswa[0].Nama = "Handi Ramadhan";
	mahasiswa[0].Nilai = 90;
	mahasiswa[1].NISN = "9963959682";
	mahasiswa[1].Nama = "Rio Alfandra";
	mahasiswa[1].Nilai = 55;
	mahasiswa[2].NISN = "9950310962";
	mahasiswa[2].Nama = "Ronaldo Valentino Uneputty";
	mahasiswa[2].Nilai = 80;
	mahasiswa[3].NISN = "9970272750";
	mahasiswa[3].Nama = "Achmad Yaumil Fadjri R.";
	mahasiswa[3].Nilai = 60;
	mahasiswa[4].NISN = "9970293945";
	mahasiswa[4].Nama = "Alivia Rahma Pramesti";
	mahasiswa[4].Nilai = 70;
	mahasiswa[5].NISN = "9952382180";
	mahasiswa[5].Nama = "Ari Lutfianto";
	mahasiswa[5].Nilai = 65;
	mahasiswa[6].NISN = "9965653989";
	mahasiswa[6].Nama = "Arief Budiman";
	mahasiswa[6].Nilai = 60;
	
	cout << "Data :\n";
	for (i = 0; i < 7; i++)
		cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
	cout << "\nPilih metode sort : \n1.Bubble Sort \n2.Selection Sort \n3.Insertion Sort" << endl;
	cin >> menu_sort;
	if (menu_sort == 1){
		cout << "\nUrutan data berdasarkan NISN :" << endl;
		//bubble NISN :
		for (i = 0; i < 7-1; i++){
			for (j = 0; j < 7-1-i;j++){
				if (mahasiswa[j].NISN > mahasiswa[j+1].NISN){			
					temp = mahasiswa[j];
					mahasiswa [j] = mahasiswa[j+1];
					mahasiswa [j+1] = temp;	
				}
			}
		}
		//print
		for (i = 0; i < 7; i++)
			cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
		
		cout << "\nUrutan data berdasarkan Nilai :" << endl;
		//bubble Nilai :
		for (i = 0; i < 7-1; i++){
			for (j = 0; j < 7-1-i;j++){
				if (mahasiswa[j].Nilai > mahasiswa[j+1].Nilai){			
					temp = mahasiswa[j];
					mahasiswa [j] = mahasiswa[j+1];
					mahasiswa [j+1] = temp;	
				}
			}
		}
		//print
		for (i = 0; i < 7; i++)
			cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
	}
	if (menu_sort == 2){
		cout << "\nUrutan data berdasarkan NISN :" << endl;
		//selection NISN :
		for (i = 0; i < 7-1 ;i++){
			int min = i;
			for (j = i+1; j < 7; j++){
				if (mahasiswa[j].NISN < mahasiswa[min].NISN)
					min = j;
			}
			temp = mahasiswa[i];
			mahasiswa [i] = mahasiswa[min];
			mahasiswa [min] = temp;	
		}	
		//print
		for (i = 0; i < 7; i++)
			cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
		
		cout << "\nUrutan data berdasarkan Nilai :" << endl;
		//selection Nilai :
		for (i = 0; i < 7-1 ;i++){
			int min = i;
			for (j = i+1; j < 7; j++){
				if (mahasiswa[j].Nilai < mahasiswa[min].Nilai)
					min = j;
			}
			temp = mahasiswa[i];
			mahasiswa [i] = mahasiswa[min];
			mahasiswa [min] = temp;
		}
		//print
		for (i = 0; i < 7; i++)
			cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
		
	}
	if (menu_sort == 3){
		cout << "\nUrutan data berdasarkan NISN :" << endl;
		//insertion NISN :
		for ( i = 0; i < 7-1; i++){
			string key = mahasiswa[i+1].NISN;
			temp = mahasiswa[i+1];
			for (j = i; key < mahasiswa[j].NISN && j >= 0 ; j--){
				mahasiswa[j+1] = mahasiswa[j];
			}
			mahasiswa[j+1] = temp;
		}
		//print
		for (i = 0; i < 7; i++)
			cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
		
		cout << "\nUrutan data berdasarkan Nilai :" << endl;
		//insertion Nilai :
		for ( i = 0; i < 7-1; i++){
			int key = mahasiswa[i+1].Nilai;
			temp = mahasiswa[i+1];
			for (j = i; key < mahasiswa[j].Nilai && j >= 0 ; j--){
				mahasiswa[j+1] = mahasiswa[j];
			}
			mahasiswa[j+1] = temp;
		}
		//print
		for (i = 0; i < 7; i++)
			cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
	}
	cout << "-----------------------------------------------------------" <<endl;
	//binary search
	cout << "\nUrutan data berdasarkan NISN :" << endl;
	//insertion NISN :
	for ( i = 0; i < 7-1; i++){
		string key = mahasiswa[i+1].NISN;
		temp = mahasiswa[i+1];
		for (j = i; key < mahasiswa[j].NISN && j >= 0 ; j--){
			mahasiswa[j+1] = mahasiswa[j];
		}
			mahasiswa[j+1] = temp;
	}
	//print
	for (i = 0; i < 7; i++)
		cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
			
	binary_search (mahasiswa, 0, 6, "9950310962");
	
	cout << "-----------------------------------------------------------" <<endl;
	//sequential search
	for (i = 0; i < 7 ; i++){
		if (mahasiswa[i].Nilai == 60)
			mahasiswa[i].Nama = "Joko";		
	}
	//print
	cout << "\nData setelah nama diubah menjadi Joko :" << endl;
	for (i = 0; i < 7; i++)
		cout << mahasiswa[i].NISN << "\t" << mahasiswa[i].Nama << "\t" <<mahasiswa[i].Nilai << endl;
		
	return 0;
}

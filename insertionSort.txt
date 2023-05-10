#include <algorithm>
#include<iostream>
#include<random>
using namespace std;
void display(int array[], int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout<<endl;
   cout<<endl;
}

void insertionSort(int array[], int size) {
   int key, j, comp=0, no_swap=0;;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      comp++;
      while(j > 0 && array[j-1]>key) {
      	 
         array[j] = array[j-1];
         j--;
         comp++;
      }
      
      array[j] = key;
      no_swap++;
   }cout<<"no of comparison for insertion sort:"<<comp<<"\n";
   cout<<endl;
   cout<<endl;
}
void bestcase(int array[], int size){
	for(int i=0; i<=size; i++){
		array[i]=rand()%1000;
		
	}
	sort(array, array+20);
	cout<<"Array for Best case:";
	cout<<endl;
	display(array, size);
	
	insertionSort(array, size);
	display(array, size);
}
void worstcase(int array[], int size){
	for(int i=0; i<=size; i++){
		array[i]=rand()%1000;
		
	}
	sort(array, array+size,greater<int>());
	cout<<"Array for worstcase:";
	cout<<endl;
	display(array, size);
	
	insertionSort(array, size);
	display(array, size);
}
int main() {
    
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];    
   //cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      arr[i]=rand()%1000;
   }
   cout << "Array before Sorting: ";
   cout<<endl;
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
   int n2;
   cout<<"enter the size of array for best case:";
   cin>>n2;
   int arr2[n2];
   bestcase(arr, n2);
   int n3;
   cout<<"enter the size of array for worst case:";
   cin>>n3;
   int arr3[n3];
   worstcase(arr, n2);
   
}
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;
int c=0;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low- 1;
 
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        c++;
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int ran_partition(int arr[],int l, int r){
	int i=l+rand()%(r-l);
	swap(arr[r],arr[i]);
	return partition(arr,l,r);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = ran_partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generate_random_array(int arr[], int size){
	for(int i=0; i<size; i++){
		arr[i] = rand()%100;
	}
}

void array_worst(int m, int min = 30, int max = 1000){
	int interval = (max - min)/m;
	int count=0;
	ofstream file;
	file.open("QS_worst_case.csv",ios::app);
	file<<"Size"<<","<<"Comaprisons"<<endl;
	for (int size = min; count< m; size+=interval, count++){
		c=0;
		int *arr = new int[size];
		generate_random_array(arr,size);
		std::sort(arr,arr+size);
		quickSort(arr,0,size-1);
		file<<size<<","<<c<<endl;
		delete[] arr;
	}
	file.close();
}

void array_avg(int m, int min = 30, int max = 1000){
	int interval = (max - min)/m;
	int count=0;
	ofstream file;
	file.open("QS_average_case.csv",ios::app);
	file<<"Size"<<","<<"Comaprisons"<<endl;
	for (int size = min; count< m; size+=interval, count++){
		c=0;
		int *arr = new int[size];
		generate_random_array(arr,size);
		quickSort(arr,0,size-1);
		file<<size<<","<<c<<endl;
		delete[] arr;
	}
	file.close();
}

int main()
{
	array_worst(50);
	array_avg(50);
	
	return 0;
}

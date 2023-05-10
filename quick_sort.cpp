/* 
 * 
 * 
 * Program by Om Gupta (214047)
 */


#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include "../array.hpp"

#define NO_OF_INPUTS 100
#define MIN_SIZE 30
#define MAX_SIZE 1000

using namespace std;

int partition(int* arr, int start, int end, int& count);
int quick_sort(int* arr, int start, int end);
void test_quick_sort(int number_of_cases, int case_type);

int main(){
    test_quick_sort(60,2); //average case
    test_quick_sort(20,1); //worst case
    test_quick_sort(20,3); //worst case
    return 0;
}

int partition(int* arr, int start, int end, int& count){
    int i = start -1;
    int pivot = arr[end];
    for (int j = start; j<end; j++){
        if (arr[j] < pivot){
            count++;
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

int quick_sort(int* arr, int start, int end){
    int comparisons = 0;
    if (start < end){
        int p = partition(arr, start, end, comparisons);
        comparisons += quick_sort(arr, start, p-1);   
        comparisons += quick_sort(arr, p+1, end);   
    }
    return comparisons;
}



void test_quick_sort(int number_of_cases, int case_type){
    int interval = (MAX_SIZE-MIN_SIZE)/number_of_cases;
    int *test_array, comparisons, count=0;

    // Opening csv file
    ofstream fout;
    string fname = "quick_sort_case_"+to_string(case_type);
    fout.open(fname+".csv");
    fout<<"size,comparisons,nlogn\n";

    for (int i = MIN_SIZE; count<number_of_cases; i+=interval, count++){
        test_array = new int[i];
        generate_array(test_array, i, case_type);
        comparisons = quick_sort(test_array,0,i-1);
        fout<<i<<','<<comparisons<<','<<i*log10(i)<<'\n';
    }
    fout.close();
}
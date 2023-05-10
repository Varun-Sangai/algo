#include <iostream>
#include <algorithm>
#include <cstdlib> 

using namespace std;

int partition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (A[j] <= pivot)
        {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int r_partition(int A[], int l, int r)
{
    int i = l + rand() % (r - l + 1); 
    swap(A[r], A[i]); 
    return partition(A, l, r); 
}

int randomizedSelect(int A[], int l, int r, int i)
{
    if (l == r) 
        return A[l];
    int q = r_partition(A, l, r);
    int k = q - l + 1; 
    if (i == k) 
        return A[q];
    else if (i < k) 
        return randomizedSelect(A, l, q - 1, i);
    else 
        return randomizedSelect(A, q + 1, r, i - k);
}

int main()
{
    int A[] = {2, 7, 5, 9, 4, 6, 3, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int i = 4; 
    cout << i<<"th smallest element is "<<randomizedSelect(A, 0, n - 1, i); 
    return 0;
}

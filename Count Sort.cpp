#include <iostream>
using namespace std;

int getMax(int arr[], int n) {  
   int max = arr[0];  
   for(int i = 1; i<n; i++) {  
      if(arr[i] > max)  
         max = arr[i];  
   }  
   return max;
}  
  
void count_sort(int arr[], int n) 
{  
   int output[n+1];  
   int max = getMax(arr, n);  
   int count[max+1]; 
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; 
  }  
    
  for (int i = 0; i < n; i++) 
  {  
    count[arr[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; 
  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[arr[i]] - 1] = arr[i];  
    count[arr[i]]--; 
}  
  
   for(int i = 0; i<n; i++) {  
      arr[i] = output[i];
   }  
}  
  
void print(int arr[], int n)
{  
    int i;
	cout<<"[";  
    for (i = 0; i < n; i++)
    {
    	cout<<arr[i]<<", ";
	}
    cout<<"]";
}  
  
int main() {  
	int n;

    cout<<"Enter number of elements: ";
    cin>>n;
	cout<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
 
    count_sort(arr, n);
    cout<<endl;
    cout<<"Sorted array: ";    
    print(arr, n);  
    return 0;  
  
} 

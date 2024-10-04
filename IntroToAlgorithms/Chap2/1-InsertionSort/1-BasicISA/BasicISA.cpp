#include <iostream>
using namespace std;

// Procedure to sort the array through the `Insertion Sort` algorithm
void insertionSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        
        arr[j+1] = key;
    }
}

// Procedure to show the array elements
void showArray(int arr[], int n){
	for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    
	const int N = 4;
    int A[N] = {3,7,2,8};
    int key;
    
    cout << "The not-sorted array is: " << endl;
    
    // show the array before being sorted by calling call the `showArray` procedure
    showArray(A,N);
    
    // call the `insertionSort` algorithm procedure
    insertionSort(A,N);
    
    cout << "The sorted array is: " << endl;
    // show the sorted array
    showArray(A,N);
    
    return 0;
}

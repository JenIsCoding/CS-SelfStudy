/* FINAL EX. 4
Write a program that allows the user to enter eight integer values. 
Display the values in the reverse order of the order they were entered. 
Name the file ReverseNumbers.cpp.*/

#include <iostream>
using namespace std;

void fillArray(int arr[], int N){
	
	for(int i = 0; i < N; i++){
		cout << "Insert a number: " << endl;
		cin >> arr[i];
	}
};

void copyArray(int arr1[], int arr2[], int N){
	// arr1 is the array we want to make a copy of
	for(int i = 0; i < N; i++){
		arr2[i] = arr1[i];
	}
};

void reverseArray(int arr[], int tempArr[], int N){
	copyArray(arr,tempArr,N);
	
	for(int i = 0; i < N; i++){
		int j = (N-1)-i;
		arr[j] = tempArr[i];
	}
};

void showArray(int arr[], int N){
	
	for(int i = 0; i < N; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
};

int main(){
	
	const int n = 8;
	int arrValues[n];
	int tempArrValues[n];
	
	cout << "START THE ARRAY FILLING PROCESS." << endl;
	fillArray(arrValues,n);
	cout << "ARRAY FILLING PROCESS COMPLETED." << endl;
	
	cout << "THE ARRAY YOU FILL IS: " << endl;
	showArray(arrValues,n);
	
	cout << "THE ARRAY PRINTED IN THE REVERSE ORDER IS: " << endl;
	reverseArray(arrValues, tempArrValues,n);
	showArray(arrValues,n);
	
	return 0;
}

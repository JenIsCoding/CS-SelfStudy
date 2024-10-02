/* EX. 2 from https://erlerobotics.gitbooks.io/erle-robotics-cpp-gitbook/content/pointers/exercises_pointers.html
Write a C++ program to find the max of an integral data set. 
The program will ask the user to input the number of data values in the set and each value. 
The program prints on screen a pointer that points to the max value.
*/

#include <iostream>
using namespace std;

int main(){
	int n,max;
	int arr[n];
	int* ptrMax;
	
	cout << "Please tell the number of integer you want to insert: " << endl;
	cin >> n;
	
	for(int i = 0; i < n ; i++){
		cout << "Please insert a number: " << endl;
		cin >> arr[i]; 
	}
	
	// Find the maximum element of the array
	
	max = arr[0];
	
	for(int i = 0; i < n ; i++){
		if(arr[i] > max){
			max = arr[i];
		} 
	}
	
	// Bind the pointer to the max
	
	ptrMax = &max;
	
	// Show the max value and its memory address
	
	cout << "The maximum element of the array is " << max << " and its memory address is " << ptrMax << "." << endl;
	
	return 0;
}


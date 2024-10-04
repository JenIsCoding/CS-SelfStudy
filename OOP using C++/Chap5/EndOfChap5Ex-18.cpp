/* FINAL EXERCISE 18
Write a program that declares an array of 10 integers. 
Write a loop that accepts 10 values from the keyboard, and write another loop that displays the 10 values. 
Do not use any subscripts within the two loops; use pointers only. 
*/

#include <iostream>
using namespace std;

int main(){
	const int n = 5;
	int arrTenInt[n];
	int* ptrToArr = arrTenInt; // Pointer to the first element of the array
	int i = 0;
	int j = 0 ;
	
	while(i < n){
		cout << "Please insert a number: " << endl;
		cin >> *(ptrToArr + i); //	Pay attention: *ptr = 1; is the same as myArr[0] = 1;
		i++;
	}
	
	cout << "The array you entered is: " << endl;
	
	while(j < n){
		cout << *(ptrToArr + j) << " ";
		j++;
	}
	
	return 0;
}


/* EX. 1 from https://erlerobotics.gitbooks.io/erle-robotics-cpp-gitbook/content/pointers/exercises_pointers.html
Write a program that asks the user to enter integers as inputs to be stored in the variables 'a' and 'b' respectively. 
There are also two integer pointers named ptrA and ptrB. 
Assign the values of 'a' and 'b' to ptrA and ptrB respectively, and display them.
*/

#include <iostream>
using namespace std;

int main(){
	int a,b;
	int* ptrA;
	int* ptrB;
	
	cout << "Please enter a number: " << endl;
	cin >> a;
	
	cout << "Please enter a second number: " << endl;
	cin >> b;
	
	ptrA = &a;
	ptrB = &b;
	
	cout << "`a` memory address is " << ptrA << endl;
	cout << "`b` memory address is " << ptrB << endl;
	
	return 0;
}


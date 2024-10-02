/* EX. 3 from https://erlerobotics.gitbooks.io/erle-robotics-cpp-gitbook/content/pointers/exercises_pointers.html
Take input in variable and display same value by pointer.
*/

#include <iostream>
using namespace std;

int main(){

   int myVar;
   int *ptrVar;
   
   cout << "Please enter a number: " << endl;
   cin >> myVar;
   
   ptrVar = &myVar;
   
   cout<< " The pointer value is "<< *ptrVar << " and its memory address is: "<<  ptrVar;
   
   return 0;
}

/* 
`cout << ptrVar;`
	This will output the memory address stored in the pointer `myVar`. 
	Since `ptrVar` is a pointer to `myVar`, it holds the memory location where `myVar` is stored. 
	The output will be the address in hexadecimal format (unless you change the default formatting).

`cout << *ptrVar;`
    This will output the value pointed to by `ptrVar`.  Here, `ptrVar` points to `myVar`, so it will show its value.
*/

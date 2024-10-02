/* EX. 4 from https://erlerobotics.gitbooks.io/erle-robotics-cpp-gitbook/content/pointers/exercises_pointers.html
Given the string "A string.", print on one line the letter on the index 0, the pointer position and the letter t. 
Then, undate the pointer to pointer +2. 
Then, in another line print the pointer and the letters r and g of the string (using the pointer).
*/

#include <iostream>

using namespace std;

int main(){

	char str[] = "A string.";
	char *ptrStr = str;

   cout << "The letter at index 0 is " << str[0] << ", its memory location is "<< static_cast<void*>(ptrStr) << endl;
   cout << "The letter at index 3 is "<< ptrStr[3]<< "\n";
   ptrStr += 2;
   cout << "The pointer is now tied up at letter `s` of the original string, no more at the capital `A` of the beginning." << endl;
   cout << "Now by the `ptrStr[2]` command, I can find the letter " << ptrStr[2] << endl;
   cout << "and by the `ptrStr[5]` command, I can find the letter " << ptrStr[5] << endl;

   return 0;

}


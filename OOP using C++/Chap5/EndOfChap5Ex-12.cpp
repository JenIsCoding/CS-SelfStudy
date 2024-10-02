/* FINAL EX. 12
Write a program that accepts your first name into a character array string variable. 
Print your name backward. 
For example, if your name is Lisa, display asiL.
*/

#include <iostream>
using namespace std;

// Get length of a string without using any other C++ library
int getStrLen(char arrStr[]){
	int i=0;

    while(arrStr[i] != '\0'){
        i++;
    }

    return i;
}

// Make a copy of a string
void copyStr(char arrStr[], char copyArrStr[]){
	int len = getStrLen(arrStr);
	for(int i = 0; i < len; i++){
		copyArrStr[i] = arrStr[i];
	}
}

// Reverse the order of a given string
void reverseName(char arrStr1[], char arrStr2[], int len){
	
	for(int i = 0; i < len; i++){
		int j = (len-1)-i;
		arrStr2[j] = arrStr1[i];
	}
}

// Show a string
void showStr(char arr[], int N){
	
	for(int i = 0; i < N; i++){
		cout << arr[i];
	}
};

int main(){
	
	char userName[100];
	int strLen;
	
	cout << "Write your name: " << endl;
	cin >> userName;
	
	strLen = getStrLen(userName);
	
	// Make a copy of the original username string
	char changeUserName[strLen];
	copyStr(userName,changeUserName);
	
	// Reverse the username string
	reverseName(userName,changeUserName, strLen);
	
	// Show the name in the reverse order
	showStr(changeUserName,strLen);
	
	return 0;
}

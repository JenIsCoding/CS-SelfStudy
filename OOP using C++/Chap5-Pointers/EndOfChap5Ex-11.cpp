/* FINAL EX. 11
Write a program that accepts your first name into a character array string variable. 
Display your name with an asterisk between each letter. 
For example, if your name is Lisa, display L*i*s*a.
*/

#include <iostream>
using namespace std;

// Get the length of a string without using any extra C++ library
int getStrLen(char arrStr[]){
	int i=0;

    while(arrStr[i] != '\0'){
        i++;
    }

    return i;
}

// Add asterisk between two letters of a string
void addAsteriskInName(char arrStr1[], char arrStr2[], int len){
	
	for(int i = 0; i < len; i++){
		if(i%2 == 0){
			arrStr2[i] = arrStr1[i/2];
		} 
		else{
			arrStr2[i] = '*';
		}
	}
}

// Show a string
void showString(char arr[], int N){
	
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
	
	int otherStrLen = (strLen * 2) - 1;
	
	char otherUserName[otherStrLen];
	
	addAsteriskInName(userName,otherUserName,otherStrLen);

	//	showString(otherUserName,otherStrLen);
	cout << "Adding asterisks..." << endl;
	
	cout << otherUserName << endl;
	
	cout << "Asterisks had been added to your name :)" << endl;
	
	return 0;
}

/* FINAL EX. 17
The O’Neill High School Performing Arts Center auditorium contains 20 rows (numbered 1 through 20) with 40 seats each (numbered 1 through 40). 
Write an application that allows a user to continuously enter a row and seat request until a sentinel value is entered. 
If the row or seat number is too high, issue an error message. 
Otherwise, determine whether the seat has already been reserved. If so, display an error message; if not, then charge the user $7.50 for a ticket 
and display a running total of the user’s purchase. 
When the user enters a sentinel, display the number of seats taken and the number still available in the auditorium.
*/

#include <iostream>
using namespace std;

// Get length of a string without using any other C++ library
//int getStrLen(char arrStr[]){
//	int i=0;
//
//    while(arrStr[i] != '\0'){
//        i++;
//    }
//
//    return i;
//}

// Make a copy of a string
//void copyStr(char arrStr[], char copyArrStr[]){
//	int len = getStrLen(arrStr);
//	for(int i = 0; i < len; i++){
//		copyArrStr[i] = arrStr[i];
//	}
//}

// Reverse the order of a given string
//void reverseName(char arrStr1[], char arrStr2[], int len){
//	
//	for(int i = 0; i < len; i++){
//		int j = (len-1)-i;
//		arrStr2[j] = arrStr1[i];
//	}
//}

// Show a string
//void showStr(char arr[], int N){
//	
//	for(int i = 0; i < N; i++){
//		cout << arr[i];
//	}
//};

int getOccupiedSeatsNum(int arr[][2], int len){
	int getLen = 0;
	for (int k = 0; k < len; k++) {
        if (arr[k][0] != 0 || arr[k][1] != 0) {
            getLen++;
        }
    }
	return getLen;
}

int main(){
	const int numOfRows = 20;
	const int numOfSeats = 40;
	const int dim = numOfRows*numOfSeats;
	
	int occupiedSeats[dim][2] = {
		{1,1},{2,4},{11,3},{19,5},{18,35},{20,40}
	};
	int getNumOccSeats = getOccupiedSeatsNum(occupiedSeats,dim);
	cout << "The number of occupied seats is " << getNumOccSeats << endl;
	
	int userPrefs[numOfRows*numOfSeats][2];
	
	int count = 0;
	int prefRow = 0;
	int i = 0;
	int j = 0;
	int prefSeat;
	
	do{
		// User must choice a row number 
		cout << "Please insert the number of row you would like: "<< endl;
		cin >> userPrefs[i][0];
		
		if(prefRow > numOfRows){
			cout << "The row number must be between 1 and " << numOfRows << "." << endl;
		} 
		else if(prefRow == -1){
			break;
		}
		
		// User must choice a seat number 
		cout << "Please insert the number of seat you would like: "<< endl;
		cin >> userPrefs[i][1];

		if(prefSeat > numOfSeats || prefSeat < 1){
			cout << "The seat number must be between 1 and " << numOfSeats << "." << endl;
		}
		
		cout << "user seat number choice is "<< userPrefs[i][0] << endl;
		cout << "user seat row choice is "<< userPrefs[i][1] << endl;
		i++;
		cout << "Now count is " << i << endl; 
		
	}while(prefRow != -1); // this is the sentile value I choose
	
	
	return 0;
}

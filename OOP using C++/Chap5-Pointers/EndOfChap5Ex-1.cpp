/*FINAL EXERCISE 1 
Riley Residence Hall charges different rates for semester room and board based on the number of meals per day the student wants. 
The semester rate with no meals is $300. 
With one meal per day, the rate is $450. 
With two meals per day, the rate is $520, and
with three meals per day, the rate is $590. 
Store these rates in an array. Write a program that allows a student to enter the number of meals desired per day. 
Output the semester room and board rate. 
Name the file SemesterMeals.cpp.*/

#include <iostream>
using namespace std;

void getRates(int arr[4][2], int par){
	if(arr[par][0] == par){
		cout << "The semester rate with " << par << " meals is " << arr[par][1] << "$." << endl;
	}
}

int main(){
	
	int numberMeals;
	int semesterRate[4][2] = {
		{0,300},
		{1,450},
		{2,520},
		{3,590}
	};
	
	cout << "Please tell me the number of meal you would like: " << endl;
	cin >> numberMeals;
	
	do {
		if (numberMeals < 0 || numberMeals > 3) {
            cout << "The you entered is invalid! Number must be between 0 and 3." << endl;
            cout << "Please tell me the number of meal you would like: " << endl;
			cin >> numberMeals;
        } 
		else{
        	getRates(semesterRate,numberMeals);
			break;
			}
    } while(numberMeals > -1);
	
	if(numberMeals < 0){
		cout << "The number of meal(s) must be a positive! Please try again!"<< endl;
	}

	return 0;
}

/*FINAL EXERCISE 1 
Write a program that allows the user to enter seven double values representing store sales for each day of one week. 
After all seven values are entered, echo them to the screen, and display highest and lowest sales values. 
Name the file DailySales.cpp.*/

#include <iostream>
using namespace std;

void showUserStoreSales(const char* arr1[], double arr2[], int N){
	for(int i = 0; i < N; i++){
		cout << arr1[i] << " store sales = " << arr2[i] << "$." << endl;
	}
};

int findMin(double arr[], int N){
	double min = arr[0];
	int minIndex = 0;
	for(int i = 1; i < N; i++){
		if(arr[i] < min){
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
};

int findMax(double arr[], int N){
	double max = arr[0];
	int maxIndex = 0;
	for(int i = 1; i < N; i++){
		if(arr[i] > max){
			max = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
};

int main(){
	
	const int n = 7;
	
	const char* dayOfWeek[n] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday",	
	};
	
	double storeSales[n];
	
	int minSaleInd, maxSaleInd;
		
	for(int i = 0; i < n; i++){
		cout << "Please insert the "<< dayOfWeek[i] << " store sales expressed in $." << endl;
		cin >> storeSales[i];
	};
	
	cout << endl;
	cout << endl;
	
	cout << "WEEKLY STORE SALES: " << endl;
	showUserStoreSales(dayOfWeek,storeSales,n);
	cout << endl; 
	cout << endl;
	
	minSaleInd = findMin(storeSales,n);
	cout << "The minimum sale was " << storeSales[minSaleInd] << "$ on " << dayOfWeek[minSaleInd] << "." << endl;
	maxSaleInd = findMax(storeSales,n);
	cout << "The maximum sale was " << storeSales[maxSaleInd] << "$ on " << dayOfWeek[maxSaleInd] << "." << endl;
	
	return 0;
}

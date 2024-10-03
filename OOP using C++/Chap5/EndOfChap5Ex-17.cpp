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

// Calculate the number of already reserved seats
int getReservedSeatsNum(int arr[][2], int len){
	int getLen = 0;
	for (int k = 0; k < len; k++) {
        if (arr[k][0] != 0 || arr[k][1] != 0) {
            getLen++;
        }
    }
	return getLen;
}

// heck if the row and seat chosen by the customer are available
bool checkIfAvailable(int arr[][2], int len, int R, int S){
	for(int i = 0; i < len; i++){
		if(arr[i][0] == R && arr[i][1] == S){
			return false; // row and seat reserved
		}
	}
	return true; // row and seat available
}

// Show the row(s) and seat(s) chosen by the user before purchase
void showPurchasedSeats(int arr[][2], int len){
	
	for(int i = 0; i < len; i++){
		cout << "Row " << arr[i][0] << " - Seat " << arr[i][1] << endl;
	}
};

// Show the number of reserved seats
void showResSeats(int num, int tot){
	cout << "Number of seats taken in the auditorium: " << num << endl;
	cout << "Number still available in the auditorium: " << tot-num << endl;
}

// Show all the reserved seats 
// (this is a function reserved for auditorium workers only, been launched when `2` is chosen)
void showResSeatsForStaff(int arr[][2], int len){
	cout << "All the reserved seats are listed below: " << endl;
	
	for(int i = 0; i < len; i++){
	cout << "Row " << arr[i][0] << " - Seat " << arr[i][1] << endl;
	}
}

int main(){
	// Size of the problem
	const int numOfRows = 20;
	const int numOfSeats = 40;
	const int dim = numOfRows*numOfSeats;
	
	// Array with some reserved seats
	int reservedSeats[dim][2] = {
		{1,1},{2,4},{11,3},{19,5},{18,35},{20,40}
	};
	int getNumResSeats = getReservedSeatsNum(reservedSeats,dim);
	showResSeats(getNumResSeats,dim);
	cout << endl;
	
	int userPrefs[numOfRows*numOfSeats][2];
	
	int numOfTickets = 0; // it starts as 0 and it's incremented while the user chose available seats
	const double costTicket = 7.5;
	int typeOfUser = 0;
	int prefRow = 0; // sentinel value 

	cout << "------------------START OF APPLICATION------------------" << endl;
	cout << "--------------------------------------------------------" << endl;
	
	cout << "Press `1` if you're a user, `2` if you're part of the staff." << endl;
    cin >> typeOfUser;
    
	while(typeOfUser <= -1 || typeOfUser > 2){
    	cout << "Invalid inserted number. Please choose between `1` or `2`." << endl;
    	cin >> typeOfUser;
	}
	
	// USER WINDOW
	if(typeOfUser == 1){ //user type --> go to reservation process
	
	cout << "------------------RESERVATION PROCESS------------------" << endl;
	cout << "Insert `-1` if you would like to end the reservation process."<< endl;
	cout<< endl;
	
	do{
		
		// User must choice a row number 
		cout << "Please insert the number of row you would like: "<< endl;
		cin >> userPrefs[numOfTickets][0];
		while(userPrefs[numOfTickets][0] > numOfRows){
			cout << "The row number must be between 1 and " << numOfRows << "." << endl;
			cout << "Please insert the number of row you would like: "<< endl;
			cin >> userPrefs[numOfTickets][0];
		}
		
		prefRow = userPrefs[numOfTickets][0];
		
		if(prefRow == -1){
			break;
		}
		
		// User must choice a seat number 
		cout << "Please insert the number of seat you would like: "<< endl;
		cin >> userPrefs[numOfTickets][1];
		while(userPrefs[numOfTickets][1] > numOfSeats || userPrefs[numOfTickets][1] < 1){
			cout << "The row number must be between 1 and " << numOfSeats << "." << endl;
			cout << "Please insert the number of seat you would like: "<< endl;
			cin >> userPrefs[numOfTickets][0];
		}
		
		// Check if the row and seat chosen by the customer are available
		bool isRes = checkIfAvailable(reservedSeats, dim, userPrefs[numOfTickets][0], userPrefs[numOfTickets][1]);
			// If available, the numOfTickets and the getNumResSeats variables are incremented by 1
			// Also, the row and seat chosen are added to the reservedSeats array
		if(isRes == true){
			cout << "The row and seat you choose are available :)!" << endl;
			// Add the chosen seats and rows to the reservedSeats array
			reservedSeats[getNumResSeats][0] = userPrefs[numOfTickets][0];
			reservedSeats[getNumResSeats][1] = userPrefs[numOfTickets][1];
			numOfTickets++;
			getNumResSeats++;
		} else{ // If not available, the user must choice another row and/or seat
			cout << "The row and seat you choose are already taken. Please choose different numbers." << endl;
		}
		
	}while(prefRow != -1); // This is the sentinel value I chose
	
	// FINAL PURCHASE WINDOW
	cout << endl;
	cout << "------------------BEFORE PAYMENT PROCESS------------------" << endl;
	
	if(numOfTickets == 0){
		cout << "You have decided not to buy anything for now." << endl;
		cout << "If you change your mind, we're here for you. :)" << endl;
	}
	else if(numOfTickets == 1){
		cout << "You are about to complete your purchase." << endl;
		cout << "You chose the following seat: " << endl;
		showPurchasedSeats(userPrefs, numOfTickets);
	}
	else{
		cout << "You are about to complete your purchase." << endl;
		cout << "You chose the following seats: " << endl;
		showPurchasedSeats(userPrefs, numOfTickets);
	}

	cout << "Total purchase cost is " << costTicket * numOfTickets << "$." << endl; 
	
	cout << endl;
	cout << "------------------PAYMENT PROCESS------------------" << endl;
	cout << "Which payment method do you prefer?" << endl;
	
	cout << endl;
	cout << "------------------END OF RESERVATION PROCESS------------------"<<endl;
	showResSeats(getNumResSeats,dim);	
	} 
	
	// STAFF WINDOW
	else if(typeOfUser == 2){//staff user type --> show the detailed list of the seats already reserved
		cout << endl;
		cout << "------------------DETAILED LIST OF ALREADY RESERVED SEATS------------------" << endl;
		showResSeatsForStaff(reservedSeats, getNumResSeats);
	} 
	
	return 0;
}

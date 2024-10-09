#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

// With this `struct`, I create a card, made like this:
// - card face, e.g. "J" or "1" or "K"
// - card value, e.g. 8 or 9 or 11 for a "Q" card
// - card suit, e.g. spades or clubs
	struct Card{
		string cardFace;
    	int cardValue;
    	string cardSuit;
	};

// Random number generator  
int rndmNumGen(int par){
	int randomNum = rand() % par; // generate a number between 0 and "par-1"
	return randomNum;
}

// Random card array generator
void rndmCardArrGen(string arrStr[], int arrInt[], string arrType[], Card rndmCardArray[], int N){
// inputs explanation:
// - arrStr --> corresponds to "cardsListFaces"
// - arrInt --> corresponds to "cardsListValues"
// - arrType --> corresponds to "cardsListSuits"
// - Card --> corresponds to "getCards", a new card deck that is generated here randomly
// - N --> corresponds to "numWantedCards"

	int getCardValueInd, getCardSuitInd;
	
	for(int i = 0; i < N; i++){
		// Generate a random number from 0 to 12 for the card value 
		// e.g. if I got 0 as a generated random number, it will be used as index for the cardsListValues[0] = 1
		getCardValueInd = rndmNumGen(13);
		// Generate a random number from 0 to 3 for the card suit
		// e.g. if I got 0 as a generated random number, it will be used as index for the cardsListSuits[0] = "C" 
		getCardSuitInd = rndmNumGen(4);
		
		// Assign the generated numbers to card using the for cycle
		rndmCardArray[i].cardFace = arrStr[getCardValueInd];
		rndmCardArray[i].cardValue = arrInt[getCardValueInd];
		rndmCardArray[i].cardSuit =  arrType[getCardSuitInd];
		
		// Important step: check for duplicates
		// I want to avoid to have two cards with the same value and suit (e.g.: two 6 of clubs)
		for(int g = i - 1; g >= 0; g--){
			// The while cycle compares the currently generated cardFace and carsSuit 
			// with all the card faces and suits previously generated for the other cards
			while (rndmCardArray[g].cardFace == rndmCardArray[i].cardFace && 
                   rndmCardArray[g].cardSuit == rndmCardArray[i].cardSuit){
				   // If a duplicate is found, it generates a new random number for suit only
				   getCardSuitInd = rndmNumGen(4);
				   rndmCardArray[i].cardSuit =  arrType[getCardSuitInd];
            }
		}
		
	}	
	cout << endl;	
}


// Get indexes of the 4 suits families; they will be checked in the order give by the `cardsListSuits` array
// "p", "f", "q", "c" (Italian version) or "C", "D", "H", "S" (English version)
void getSuitsIndexes(Card rndmCardArray[], int N, string arrSuits[], int M, int arrIndex[], int countSuits[]){
	int k = 0;
	
	for(int j = 0; j < M ; j++){
		int sumSuits = 0;
		for(int i = 0; i < N; i++){
			if(rndmCardArray[i].cardSuit == arrSuits[j]){
				sumSuits++;
				countSuits[j]=sumSuits;
				arrIndex[k] = i;
				k++;
			}
		}
	}

}

// Get cards sorted by suits only (not in ascending order yet) using the `arrIndex` array got previously through the `getSuitsIndexes` procedure
void sortCardsBySuits(Card rndmCardArray[], int N, int arrIndex[], Card copyCard[]){
	
	// the cards are sorted in the order given by the values that are stored in the `arrIndex` array
	for(int k = 0; k < N ; k++){
		copyCard[k].cardFace = rndmCardArray[arrIndex[k]].cardFace;
		copyCard[k].cardValue = rndmCardArray[arrIndex[k]].cardValue;
		copyCard[k].cardSuit = rndmCardArray[arrIndex[k]].cardSuit;
	}
}

// -------------------------- PROCEDURE TO SORT CARDS BY ASCENDING VALUES -------------------------- 

// Get start index for the second loop of `insertionSort` procedure
int getStartIndex(int arr[], int N, int index){
	int startInd = 0; 
	
	if(index != 0){
		for(int i = 0; i < index; i++){
			startInd += arr[i];
		}
	}
	
	return startInd;
}

// Get end index for the second loop of `insertionSort` procedure
int getEndIndex(int arr[], int N, int index){
	int endInd = arr[0]; 
	
	for(int i = 1; i <= index; i++){
		endInd = endInd + arr[i];
	}
	
	return endInd;
}

// Procedure to sort the struct through the `Insertion Sort` algorithm
void insertionSort(Card givenDeck[], int N, int numSuits, int countSuits[]){
	
	for(int k = 0; k < numSuits; k++){
		
		int iStart = getStartIndex(countSuits,numSuits,k);
		int iEnd = getEndIndex(countSuits,numSuits,k);
		
		for(int i = iStart; i < iEnd; i++){
			// Use all the struct as a key, not the age only
            Card key = givenDeck[i]; 

			int j = i - 1;
				
			while(j >= iStart && givenDeck[j].cardValue > key.cardValue){

				givenDeck[j+1] = givenDeck[j];

            	j = j - 1;
				}
			givenDeck[j+1] = key;
			
			}

	}
		
}

// -------------------------- PROCEDURES TO SHOW CARDS OR ARRAYS -------------------------- 

// Procedure to show the array elements
void showArray(int arr[], int n){
	for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Procedure to show the struct elements
void showStructEl(Card cards[], int n){
	for(int i = 0; i < n; i++){
//        cout << cards[i].cardFace << "(" << cards[i].cardValue << ")" << cards[i].cardSuit << endl;
        cout << cards[i].cardFace << cards[i].cardSuit << endl;
    }
    cout << endl;
}


// ----------------------------------- MAIN PART ------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------

int main(){
	
	srand(time(NULL));
	
	const int numTotCards = 13; //number of cards per suit
	const int numSuits = 4; //number of suits cards 
	const int numWantedCards = 7; //number of cards to be sorted aka number of starting deck
	
	// List of cards as strings
	string cardsListFaces[numTotCards]= {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	// List of cards value
	int cardsListValues[numTotCards] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	// List of suits [italian]
	string cardsListSuits[numSuits] = {"C", "D", "H", "S"};//{"p", "f", "q", "c"};//
	
	// new Card instance definition, based on `numWantedCards`
	Card getCards[numWantedCards];
	
	// Generate a random `numWantedCards` deck of nCards 
	rndmCardArrGen(cardsListFaces, cardsListValues, cardsListSuits, getCards, numWantedCards);
	
	// Show suits legend to user
	cout << "Suits legend: " << endl;
	cout << "C = Clubs" << endl;
	cout << "D = Diamonds" << endl;
	cout << "H = Hearts" << endl;
	cout << "S = Spades" << endl;
	cout << endl;
	
	// Show the generated cards elements
	cout << "These are the cards generated randomly: " << endl;
	showStructEl(getCards, numWantedCards);
	
	// get indexes of different suit families
	int arrOfIndx[numWantedCards]={0};
	int getSuitsNum[numSuits]={0};
	getSuitsIndexes(getCards, numWantedCards, cardsListSuits, numSuits, arrOfIndx, getSuitsNum);
	cout << "These are the cards grouped by suit but not sorted yet: " << endl;
//	showArray(arrOfIndx,numWantedCards);
	
	// new Card instance to make a new sorted `getCards` struct ordered by suits
	Card newSortedCards[numWantedCards];
	
	// Sort cards by suits (not sorted yet) and putting them into the `newSortedCards` struct
	sortCardsBySuits(getCards, numWantedCards, arrOfIndx, newSortedCards);
	
	// Show cards by suit 
	showStructEl(newSortedCards, numWantedCards);
	
	// insertionSort procedure
	insertionSort(newSortedCards, numWantedCards, numSuits, getSuitsNum);
	
	// Show sorted deck card by suit 
	cout << "Sorted cards by suit: " << endl;
	showStructEl(newSortedCards, numWantedCards);

	
	//indexes
//	int start = getStartIndex(getSuitsNum, 4, 0);
//	cout << "start 0 ind = " << start << endl;
//	int end = getEndIndex(getSuitsNum, 4, 0);
//	cout << "end 0 ind = " << end << endl;
//	start = getStartIndex(getSuitsNum, 4, 1);
//	cout << "start 1 ind = " << start << endl;
//	end = getEndIndex(getSuitsNum, 4, 1);
//	cout << "end 1 ind = " << end << endl;
//	start = getStartIndex(getSuitsNum, 4, 2);
//	cout << "start 2 ind = " << start << endl;
//	end = getEndIndex(getSuitsNum, 4, 2);
//	cout << "end 2 ind = " << end << endl;
//	start = getStartIndex(getSuitsNum, 4, 3);
//	cout << "start 3 ind = " << start << endl;
//	end = getEndIndex(getSuitsNum, 4, 3);
//	cout << "end 3 ind = " << end << endl;
	
//	const int N = 4;
//    int A[N] = {3,7,2,8};
//    
//    cout << "The not-sorted array is: " << endl;
//    
//    // show the array before being sorted by calling call the `showArray` procedure
//    showArray(A,N);
//    
//    // call the `insertionSort` algorithm procedure
//    insertionSort(A,N);
//    
//    cout << "The sorted array is: " << endl;
//    // show the sorted array
//    showArray(A,N);
  
    return 0;
}

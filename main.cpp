// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
//
// Desctription: 
//
// Assumptions:

#include "EncryptWorld.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string phrase;
	EncryptWorld ew;
	cout << "Enter phrase to encrypt!";
	getline(cin, phrase);
	ew.setPhrase(phrase);
	string cryptoPhrase = ew.encrypt();
	
	cout << cryptoPhrase << "\n";

	char keepGuessing;

	cout << "Care to guess the shift? y/n";

	cin >> keepGuessing;

	while (keepGuessing == 'y') {

		int g1;
		
		cout << "enter your guess \n";
		cin >> g1;
		
		int g1Result = ew.checkShift(g1);

		if (g1Result == 1) {
			cout << "Guess too high\n";
			cout << "guess again? y/n \n";
			cin >> keepGuessing;
		}
		else if (g1Result == -1) {
			cout << "Guess too low\n";
			cout << "guess again? y/n \n";
			cin >> keepGuessing;
		}
		else if (g1Result == 0) {
			cout << "You guessed correct!\n";
			cout << "the shift was " << g1 << "\n";
			keepGuessing = 'n';
			
		}

	}


	int guess = ew.getGuessCount();
	cout << "It took you " << guess << " tries\n";


	int avg = ew.getAvgGuess();
	cout << "Your average guess was: " << avg << "\n";

	ew.objectOff(false);

	ew.objectReset();

	ew.objectOff(true);
	
	avg = ew.getAvgGuess();
	cout << "Your average guess was: " << avg << "\n";

	cin >> guess;


		 
	
}

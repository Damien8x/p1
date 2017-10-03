// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
//
// Description: class aims to provide functions in a logical, efficient format, capable of encrypting passed strings greater than 3 characters, using a caesar cryptic shift.
// In addition, class provides necessary functions to fascilitate a guessing game from passed data in relation to the shift value used during encryption.
// Statistics are also provided modularly through accesor methods for UI benefits. Minimal error handling provided through the class. prompts will display indicating improper data
// but error handling on the application side will be necessary to maintain integrity of the program. Object's encryption may be turned off though a public function, as well as 
// the ability to reset an object to its intitial state. Specifics regarding public methods have been laid out below.
//
// Assumptions: class will be utilized for its intended purporse of encryption followed by an interactive guessing game which provides statitical feedback. Failure to succesfuly encrypt
// a phrase prior to calling checkShift() method or any accesor methods will yield insignifcant data. The use of the objectReset() method should only be used to clear all existing data
// and return object to its initial state. by using the encryptionOff() method you prevent  encryption and ability to randomize a new shift value. Error handling will consist of console prompts
// to enter acceptable data and pre-determined return values stated below. Application programmers must handle improper data to ensure preconditions are met for object integrety.

#include "EncryptWorld.h"
#include <iostream>
using namespace std;

// object attributes
int shift;
bool on;
int guessCount;
double avgGuess;
int totalGuess;
int highGuessCount;
int lowGuessCount;
string phrase;

EncryptWorld::EncryptWorld()
{
	this-> shift = 0;
	this-> on = true;
	this-> guessCount = 0;
	this-> avgGuess = 0;
	this-> totalGuess = 0;
	this-> highGuessCount = 0;
	this-> lowGuessCount = 0;
	this-> phrase = "";	
}

string EncryptWorld::encrypt(string phrase)
{

	setPhrase(phrase);
	if (on == false) {
		cout << "Sorry, encryption has been disabled." << endl;
		return getPhrase();
	}
	if (phrase.length() < 4) {
		cout << "Sorry, phrase must be 4 characters or more" << endl;
		return getPhrase();
	}
	else {
			int randomShift = rand() % 9 + 1;
			shift = randomShift;
			string crypticPhrase;

			int lowerLowShift = 90 - randomShift;

			int upperHighShift = 123 - randomShift;

			int caesarShift = 26 - randomShift;

			int crypticAscii;

			for (int i = 0; i < phrase.length(); i++) {

				int ascii = int(phrase[i]);

				if (ascii == 32) {
					crypticAscii = 32;
				}
				else if (ascii >= lowerLowShift && ascii <= 90) {
					crypticAscii = ascii - caesarShift;
				}
				else if (ascii >= upperHighShift && ascii <= 123) {
					crypticAscii = ascii - caesarShift;
				}
				else {
					crypticAscii = ascii + randomShift;
				}
				char crypticChar = char(crypticAscii);
				crypticPhrase.push_back(crypticChar);
			}
			return crypticPhrase;
		}
}

int EncryptWorld::checkShift(int guess)
{
	if (guess > 9 || guess < 1) {
		cout << "please enter an integer between 1 and 9" << endl;
		return 2;
	}
	if (guess == shift)
	{
		statistics(guess, 0);
		return 0;
	}
	else if (guess > shift)
	{
		statistics(guess, 1);
		return 1;	
	}
	else
		statistics(guess, -1);
		return -1;
}

void EncryptWorld::encryptionOff(bool setting)
{
	if (setting == true)
	{
		setOn(true);	
	}
	else if (setting == false)
	{
		setOn(false);	
	}
}

void EncryptWorld::objectReset()
{
		this->shift = 0;
		this->on = true;
		this->guessCount = 0;
		this->avgGuess = 0;
		this->totalGuess = 0;
		this->highGuessCount = 0;
		this->lowGuessCount = 0;
		this->phrase = " ";
}

// helper method designed to call appropriate functions for game statistics
// precondition: accepts two arguments of type int passed from checkShift(). passed values should reflect
// user "guess" and said guess in relation to the shift value
// postcondition: new values will be set to methods setGuessCount(), setTotalGuess(), setAvgGuess() and if 1 is passed
// as integer "relativeToShift" set highGuessCount() will be called. if relativeToShift is passed as -1
// a call to setLowGuessCount() will be called.
void EncryptWorld::statistics(int guess, int relativeToShift)
{
	setGuessCount();
	setTotalGuess(guess);
	setAvgGuess(getTotalGuess(), getGuessCount());

	if (relativeToShift == 1) 
	{
		setHighGuessCount();
	}
	if (relativeToShift == -1)
	{
		setLowGuessCount();
	}
}

// Description: mutator member function, sets phrase. called from encrypt() method
// input: string
// modify: shift and phrase attributes
void EncryptWorld::setPhrase(string phrase) {
		this->phrase = phrase;
}

// Description: mutator member function, changes setTotalGuess. called from statistics() method
// input: n/a
// modify: guessCount attribute increments by 1
void EncryptWorld::setGuessCount() {
	this->guessCount++;
}

// Description: mutator member function, sets totalGuess . called from statistics() method
// input: int
// modify: totalGuess adds passed integer to itself
void EncryptWorld::setTotalGuess(int guess) {
	this->totalGuess += guess;
}

// Description: mutator member function, sets avgGuess. called from  statistics() method
// input: integer, integer
// modify: changes avgGuess to reflect avg of totalGuess and guessCount attributes
void EncryptWorld::setAvgGuess(int totalGuess, int guessCount) {
	this->avgGuess = totalGuess / guessCount;
}

// Description: mutator member function, sets highGuessCount. called from statistics() method
// input: n/a
// modify: incrememnts highGuessCount by 1
void EncryptWorld::setHighGuessCount() {
	this->highGuessCount++;
}

// Description: mutator member function, sets lowGuessCount. called from statistics() method
// input: n/a
// modify: increments lowGuessCount by 1
void EncryptWorld::setLowGuessCount() {
	this->lowGuessCount++;
}

// Description: mutator member function, sets on attribute. 
// input: boolean
// modify: changes state of on attribute
void EncryptWorld::setOn(bool setting) {
	this->on = setting;
}

bool EncryptWorld::getOn() const {
	return on;
}

string EncryptWorld::getPhrase() const {
	return phrase;
}

int EncryptWorld::getGuessCount() const{
	return guessCount;
}

int EncryptWorld::getTotalGuess() const{
	return totalGuess;
}

double EncryptWorld::getAvgGuess() const {
	return avgGuess;
}

int EncryptWorld::getLowGuessCount() const {
	return lowGuessCount;
}
int EncryptWorld::getHighGuessCount() const{	
	return highGuessCount;
}

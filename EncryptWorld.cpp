// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
//
// class aims to provide necessary functions in a readable, logical, efficient fashion to program applications
// requring a caesar encryption of strings greater than 3 characters, while providing the means to fascilitate a guessing
// game based on a passed integer value in relation to the shift value used. 

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

// mutator member function, sets phrase. called from encrypt() method
void EncryptWorld::setPhrase(string phrase) {
		this->phrase = phrase;
}

// mutator member function, increments guessCount by 1. Called per call to checkShift() through helper method statistics()
void EncryptWorld::setGuessCount() {
	this->guessCount++;
}

// mutator member function, adds totalGuessCount to itself. Called per call to checkShift() through helper method statistics()
void EncryptWorld::setTotalGuess(int guess) {
	this->totalGuess += guess;
}

// mutator member function, averages totalGuess and guessCount. Called per call to checkShift() through helper method statistics()
void EncryptWorld::setAvgGuess(int totalGuess, int guessCount) {
	this->avgGuess = totalGuess / guessCount;
}

// mutator member function, increments highGuessCount by 1. Called per call to checkShift() where return value is equal to 1, through helper method statistics.
void EncryptWorld::setHighGuessCount() {
	this->highGuessCount++;
}

// mutator member function, increments low GuessCount by 1. Called per call to checkShift() where return value is equal to -1, through helper method statistics.
void EncryptWorld::setLowGuessCount() {
	this->lowGuessCount++;
}

// mutator member function, sets value of object's "on" attribute. a passed value of "false" will disable encryption
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

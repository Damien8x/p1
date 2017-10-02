// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.2
//
// 
//
// Assumptions:

#include "EncryptWorld.h"
#include <iostream>
using namespace std;

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
		cout << "Sorry, encryption has been disabled. \n";
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

void EncryptWorld::setPhrase(string phrase) {
		this->phrase = phrase;
}

void EncryptWorld::setGuessCount() {
	this->guessCount++;
}

void EncryptWorld::setTotalGuess(int guess) {
	this->totalGuess += guess;
}

void EncryptWorld::setAvgGuess(int totalGuess, int guessCount) {
	this->avgGuess = totalGuess / guessCount;
}

void EncryptWorld::setHighGuessCount() {
	this->highGuessCount++;
}

void EncryptWorld::setLowGuessCount() {
	this->lowGuessCount++;
}

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

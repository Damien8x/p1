// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
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
	this-> shift = 3;
	this-> on = true;
	this-> guessCount = 0;
	this-> avgGuess = 0;
	this-> totalGuess = 0;
	this-> highGuessCount = 0;
	this-> lowGuessCount = 0;
	this-> phrase = " ";
	
}
EncryptWorld::EncryptWorld(string phrase)
{
	this-> phrase = phrase;
	this-> shift = 3;
	this-> on = true;
	this-> guessCount = 0;
	this-> avgGuess = 0;
	this-> totalGuess = 0;
	this-> highGuessCount = 0;
	this-> lowGuessCount = 0;
	

}


string EncryptWorld::encrypt()
{
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return getPhrase();
	}
	else {
		string phrase = getPhrase();

			string crypticPhrase;

			int lowerLowShift = 90 - shift;

			int upperHighShift = 123 - shift;

			int caesarShift = 26 - shift;

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
					crypticAscii = ascii + 3;
				}

				char crypticChar = char(crypticAscii);
				crypticPhrase.push_back(crypticChar);

			}

			return crypticPhrase;
		}
	
}

int EncryptWorld::checkShift(int guess)
{
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return 2;
	}
	else if (guess == shift)
	{
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
bool EncryptWorld::objectOff(bool setting)
{

	if (setting == true)
	{
		setOn(true);

		return true;
	}
	else if (setting == false)
	{
		setOn(false);
		return false;
	}
	else
		return true;

}

void EncryptWorld::objectReset()
{
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
	}
	else {
		int randomShift = 1 + rand() % 9;
		this->shift = randomShift;
		this->on = true;
		this->guessCount = 0;
		this->avgGuess = 0;
		this->totalGuess = 0;
		this->highGuessCount = 0;
		this->lowGuessCount = 0;
		this->phrase = " ";
	}
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
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
	}
	else {
		if (phrase.length() < 5) {
			cout << "phrase must be at least 5 characters";
		}
		else
			this->phrase = phrase;
	}
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

bool EncryptWorld::getOn() {
	return on;
}
string EncryptWorld::getPhrase() {
	return phrase;
}
int EncryptWorld::getGuessCount() {
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return -1;
	}else
	return guessCount;
}

int EncryptWorld::getTotalGuess() {
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return -1;
	}
	else
	return totalGuess;
}

double EncryptWorld::getAvgGuess() {
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return -1;
	}
	else
	return avgGuess;
}

int EncryptWorld::getLowGuessCount() {
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return -1;
	}
	else
	return lowGuessCount;
}
int EncryptWorld::getHighGuessCount() {
	if (on == false) {
		cout << "Sorry, this setting has been disabled.";
		return -1;
	}
	else
	return highGuessCount;
}

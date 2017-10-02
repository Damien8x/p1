// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.2
//
// Desctription: Class designed for applications where caesar shift encryption is necessary, with extended uses including necessary methods for a responsive encryption "shift" guessing gamae.
// encrypt() method fascilitates a  caesar shift  encryption of a string argument, with a random shift value between 1-9. EncryptWorld objects tracks data passed through its method checkShift() and 
// makes statistical data available though a number of "get" methods, including; an average of passed integers, total of all integers passed,  a count of integers passed,
// a count of integers passed less than shift value and a count of integers passed greater than shift value. intent of provided data is to make accesible the necessary information for an application capable
// of allowing users to view an encrypted phrase and make a guess of the "shift" value used. provided information can be programmed to aid or display statistics to the user. Class object is capable
// of diabling access to the encrypt() method if a boolean value of "false"  is passed to the encryptionOff() method. Access can be made available with a "true" value as an argument to the encryptionOff() method. 
// encryptionOff() will allow application programmer to deactivate encryption until a user guesses the correct shift. Other applications of the encryptionOff() method are possible and welcomed. EncryptWorldd
// object has a objectReset() method, bringing all values of object to its initial state. objectReset() allows for repeat use of object over multiple encryptions and guessing games, allowing for new, fresh
// statistics. Method particulars and change affects on object states will be laid out in the method descriptions below.

#include <iostream>
using namespace std;

class EncryptWorld
{
public:
	// definition: class constructor, called to initialize EncryptWorld object. Object is necessary to access public methods of EncryptWorld class.
	// precondition: constructor accepts no arguments. state of object is not applicable prior to call.
	// postcondition: object initialized with default values.
	EncryptWorld();


	// definition: method accepts argument of type string, with a minimum of 4 characters. passed string will be returned as an encrypted string. encryption 
	// will shift characters according to a "shift" value, which will be randomly generated with a value between 1 and 9. if "shift" value is equal to "3" all characters of passed string will
	// increment by "3" according to associated ascii value, and returned as the newly associated character; for instance, the character 'a' = 97(ascii value) will shift 3 and returned as 
	// 'd' = 100(ascii). If character in passed string is "shifted" beyond english alphabet according to new ascii value, shift will wrap back to beginning of alphabelt; for instance, the character 'y' = 121(ascii value) with  
	// a shift of "3" will be returned as "b"= 98 (ascii value). any characters of passed string outside of english alphabelt, including numbers and special characters, will 
	// shift without wrapping, aside from empty spaces, which will be returned equal to themselves. 
	// precondition: method accepts one argument of type string, with a minimum of 4 characters for succesful encryption. If EncryptWorld method encryptionOff(bool) as been 
	// called from application, prior to encrypt(string) with a passed value of false, encryption will not be possible.
	// postcondition: if conditions are met, passed string has value of 4 or more characters, and encryptionOff(bool) has not been called with "false" value as argument an ecrypted string
	// will be returned. if passed string is less than 4 characters a prompt will be displayed on console and encryption will not take place. if application has called encryptionOff(bool)
	// with "false" argument passed a prompt will display and encryption will be unavailable.
	string encrypt(string);

	// definition: assumed that method will be used as a tool to determine value of the encryption "shift" used in encrypt(string). method has three possible integer return values
	// which relate to the integer values passed to method and the current EncryptWorld "shift" value. -1 will be returned if passed argument is less than "shift" value,
	// 1 will be returned if passed argument is greater than "shift" value, 0 will be returned if passed argument is equal to "shift" value. Returned value can be utilized in application
	// to guide user's guesses towards the "shift value". 
	// precondition: EncryptWorld "shift" value will be "0" by default until encrypt(string) method is called(assigning a random value between 1-9). an integer value must be passed to argument. 
	// postcondition: EncryptWorld class utilizes checkShift(int) method to track data to be utilized by applications. Every call to method will change state of object to reflect the
	// passed integer related to "shift" value, including return values of the following EncryptWorld methods; getGuessCount() return value will increment by 1 for each call to checkShift(int),
	// getTotalGuess() return value will increase by the value of integer passed to checkShift(int), getAvgGuess() return value update to reflect an avg of all passed values to checkShift(int) post
	// object initization and prior to objectReset() call, getLowGuessCount() return value will increment by one for every return value of -1, getHighGuessCount() return value will increment by one
	// for every checkShift(int) return value of 1.
	int checkShift(int);

	// definition: Disables encryptWorld(string) from returning encryption of passed string.
	// precondition: Accepts boolean value of "true" to enable encryptWorld(string) encryption or "false" to disable.
	// postcondition: All values of object attributes will remain identical post call. calls to encryp(string) will display
	// prompt stating encryption has been disabled and not execute the method any further.
	void encryptionOff(bool);

	// definition: resets all class attributes to default values. assumed use; prior to call to encrypt(string) and subsequently checkShift(int) method, allowing for user statistics
	// associated with checkShift(int) to not include prior encryptions and "guesses".
	// precondition: object takes no arguments. if object state has not been changed post initialization, method will have no impact on object's state.
	// postcondition: will return object to original state of initialization. 
	void objectReset();

	// definition: Associated with checkShift() method, returns total "guesses" by user (calls to checkShift()).
	// precondition: if checkShift() has not been called, a default value of 0 will be returned.
	// postcondition: returns value of all calls to checkShift() method. object state not be impacted.
	int getGuessCount() const;

	// definition: Associated with checkShift() method, returns total of "guess" values by user (total of integers passed as checkShift() argument).
	// precondition: if checkShift() has not been called, a default value of 0 will be returned.
	// postcondition: returns value of all integer arguments passed to checkShift() method. object state not be impacted.
	int getTotalGuess() const;

	// definition: Associated with checkShift() method, returns average of total "guess" values and total "guesses" (checkShift() calls and total of integers passed as checkShift() arguments)
	// precondition: if checkShift() has not been called, a default value of 0 will be returned.
	// postcondition: returns average of getGuessCount() and getTotalGuessCount(). object state not be impacted.
	double getAvgGuess() const;

	// defintion: Associated with cheeckShift() method returns, the number of "guesses" less than cryptic shift value at time of call (total of -1 return values from checkShift() calls)
	// precondition: a call to checkShift() with a return value of -1 required for a return value other than the default 0.
	// postcondition: returns the number of -1 return values from previous checkShift() calls. object state not be impacted.
	int getLowGuessCount() const;

	//definition: associated with checkShift() method, returns the number of "guesses" greater than  cryptic shift value at time of call (total of 1 return values from checkShift() calls)
	// precondition: a call to checkShift() with a return value of 1 required for a return value other than the default 0.
	// postcondition: returns the number of 1 return values from previous checkShift() calls. object state not be impacted.
	int getHighGuessCount() const;	

private:
	
	void setPhrase(string);

	void statistics(int, int);
	
	void setGuessCount();

	void setTotalGuess(int);

	void setAvgGuess(int, int);

	void setHighGuessCount();

	void setLowGuessCount();

	void setOn(bool);
	
	bool getOn() const;

	string phrase;

	int shift;

	bool on;

	int guessCount;

	int avgGuess;

	int totalGuess;

	int highGuessCount;

	int lowGuessCount;

	string getPhrase() const;
};
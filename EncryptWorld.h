// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
//
// Desctription: 
//
// Assumtpions

#include <iostream>
using namespace std;

class EncryptWorld
{
public:

	// default constructor for EncryptWorld object 
	// precondition: no object
	// postcondition: object created with default values
	EncryptWorld();

	// construcor for EncryptWorld object. Takes one argument of type string. string will be assigned to user's "phrase", which will be encrypted.
	// precondition: no object
	// postcondition: object created with "phrase" set to value of passed argument. All other values will be set to default.
	EncryptWorld(string);

	// returns encrypted "phrase" using a shift of letter structure of passed "phrase" on construct or with object.setPhrase(string);
	// error message returned if no phrase exists
	// precondition: "phrase" has not been encrypted
	// postconditon: "phrase" will be encrypted
	string encrypt();

	// will return int value which corresponds to relation of the int passed and the current cryptic shift value used. 
	// precondition: method accepts integer argument to be compared to current shift value.
	// postcondition: if passed value is greater than shift value, an int value of 1 will be returned.
	//				  if passed value is less than shift value, an int value of -1 will be returned.
	//				  if passed value is equal to shift value, an int value of 0 will be returned.
	int checkShift(int);

	// designed to restrict all features of of object methods. passing a false value will result in all methods displaying an error message when called.
	// precondition: all features of object will be available upon initialization. 
	// postcondition: passing a false value will restrict all EncryptWorld method features.
	//				  if the state of objectOff is set to false, by passing a true value, all features of EncryptWorld will be made available.
	bool objectOff(bool);

	// object reset will bring all attributes of the object to the default constructor values, asside from a randomization of the cryptic shift to be between 1-9.
	// precondition: the state of EncryptWorld object will reflect all interactions since initialziation 
	// postcondition: object will be set to default values and shift will be randomized.
	void objectReset();

	// returns number of times chehckShift() method has been called prior to objectReset() being called
	// state of method uneffected by call to method
	int getGuessCount();

	// returns sum of all guesses passed through checkShift() method, prior to objectReset() being called
	// state of method uneffected by call to method
	int getTotalGuess();

	// returns avg guess value of all guesses passed through checkShift() method, prior to objectReset() being called
	// state of method uneffected by call to method
	double getAvgGuess();

	// returns a count of all submitted guesses to checkShift() method which were less than the value of the cryptic shift.
	// state of method uneffected by all to method
	int getLowGuessCount();

	// returns a count of all submitted guesses to checkShift() method which were greater than the value of the cryptic shift.
	// state of method uneffected by all to method
	int getHighGuessCount();

	// method designed to hold value of "phrase" to be encrypted
	// precondition: value held by object will reflect the state from a prior call, default value from initialization or value from initialization with passed string value.
	// postcondition: value held by object will now reflect passed string value.
	void setPhrase(string);
	



private:
	
	// called from within the checkShift() method. Method calls appropriate methods to track user's cryptic shift "guesses".
	// precondition: must pass two interger arguments; user's "guess" value and the int value determined by the checkShift() method.
	// postcondition: object.guessCount will increase by 1, object.totalGuessCount will increase by the value passed as a "guess" to the checkShift() method, 
	// avgGuessCount will be recalculated, and depending on the guess, relative to the cryptic shift, either lowGuessCount or highGuessCount will increment by 1.
	void statistics(int, int);
	
	// used to store the number of "guesses" sent to the checkShift() method.
	// precondition: guessCount will reflect number of times method has been called prior to call.
	// postcondition: guessCount will increment by 1.
	void setGuessCount();

	// used to store the total value of all "guesses" passed through the checkShift() method. Method requires one argument of type int. Argument is equal to the value passed
	// as the user's "guess"
	// preconditon: totalGuess will reflect the total value of all "guesses" prior to call of method.
	// postcondition: totalGuess will increase by the value of the user's "guess"
	void setTotalGuess(int);

	// performing arithmetic on the values of totalGuessCount and guessCount to determine the user's avg guess passed through the checkShift() method. Method takes two arguments of 
	// type int; guessCount and totalGuessCount, and stores the value avgGuess.
	// precondition: avgGuess will reflect the avg value of all guess values passed through checckShift() method, with a default of 0.
	// postcondition: avgGuess will be recalculated to reflect the new  "guess" provided by the user.
	void setAvgGuess(int, int);

	// used to store number of "guesses" passed through checkShift() method which were greater than the cryptic shift value.
	// precondition: highGuessCount will reflect the number of "guesses" greater than the cryptic shift value, with a default value of 0.
	// ponstcondition: highGuessCount will increment by 1.
	void setHighGuessCount();

	// used to store number of "guesses" passed through checkShift() method which were less than the cryptic shift value.
	// precondition: lowGuessCount will reflect the number of "guesses" less than the cryptic shift value, with a default value of 0.
	// postconditionn: lowGuessCount will increment by 1.
	void setLowGuessCount();

	// EncryptWorld object attribute designed to be an on/off setting for method access. if a false value is passed to method all EncryptWorld methods will become unavailable and will return
	// an error message.
	// precondition: default condition is true, allowing for full usage of all object methods.
	// postcondition: if a value of "false" is passed as an argument all methods will become unavailable. If a value of "true" is passed while state of "on" is "false" all methods will become available
	void setOn(bool);
	
	// returns value of "on" to be utilized by other methods to control access
	// precondition: "on" has a default value of "true" and will remain true unless a value of "false" is passed as an argument to setOn().
	// postcondition: the state of "on" will not be impacted by method call. "on"s value will be returned.
	bool getOn();

	// object variable which holds the value of "phrase", designed to store message to encrypt. Must have a value of 4 characters or an error message will be displayed.
	// precondition: default value of " ".
	// postcondition: value can be set through creating EncryptWorld object and passing a string argument of 4 or more characters, or calling the setPhrase() method and passing a string
	// of 4 or more characters. An error message will display if string is less than 4 characters.
	string phrase;

	// holds value which will be used to "shift" letters, creating a cryptic message from the "phrase" string.
	// precondition: default value of 3.
	// postcondition: value of shift will remain 3 until objectReset() method is called. the state of "shift" will be an integer between 1-9 after objectReset method is called.
	int shift;

	bool on;

	int guessCount;

	int avgGuess;

	int totalGuess;

	int highGuessCount;

	int lowGuessCount;

	string getPhrase();



};
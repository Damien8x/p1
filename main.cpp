// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
//
// Desctription: Application driver is designed to test all public funtions provided by the EncryptWorld class, including all data types and values outside or permitted range.
// Driver will mimic the intended use of class in logical order, meaning, encryption first, followed by a guessing game, and then a display of stats.
// object will then be reset (using objectReset() method) and tested again. A second object will be created to test implicit casting and demonstrate an independent state from original object.
// The functions of the EncryptWorld class are dependent on a logical order, encryption firtst, game sencond, stats and object reset last, in order to maintain any integrety to
// the object's data. A shift value will be 0 when an object is intitialized, and adjusted randomly after encrypt() method is called. A call to the checkShift() method prior to 
// encryption taking place will yield insignificant data. method encrypt() is designed to take an argument of string, greater than 3 characters. no error handling will be provided by EncryptWorld
// beyond a prompt stating data does not fit required specifications, and in the case of encrypt() a return value equal to input. Driver will test argument less than 4 characters. It is up to programmers
// to ensure any user input is stored as a string, method is capable of handling any string composed of ascii values. state of object will change upon a succesful encryption, including change of
// attributes "phrase" and "shift". 
// Method encryptionOff() will be tested with both "true" and "false" values. a "false" argument will render change to the initial state of object's "on" attribute from "true" to false. any attempt to access
// encrypt() method will result in  prompt stating "encryption disabled". we will call encrypt() post change of state to "on" attribute to test this. We will also re-enable encryption by passing a "true"
// value and retesting encrypt().
// Driver will test checkShift() method (method compares passed integer to shift value) first through a for loop which will pass all acceptable arguments to the method, where we have laid out anticipated
// postconditions in the code. Implicit casting of characters to integer values will also be tested and render a prompt from the method.  checkShift() has a significant impact on the object state.
// any call to the method with acceptable arguments will change object's "lowGuessCount", "highGuessCount", "avgGuessCount", "totalGuessCount", and "guessCount" attributes; some by incremental values
// others dependent on passed argument, as laid out per EncryptWorld.h specifications. Driver will also test arguments outside of the range 1-9 and implicit casting of doubles. Driver will
// display output for each acceptable call to checkShift(), including; integer passed, relation to shift (-1 if below, 1 if above, 0 if the same), objects highGuessCount, lowGuessCount, avgGuessCount
// guessCount and totalGuessCount, all of which will or may be impacted by call to checkShift().
// all accesor method will be tested multiple times, during the testing of the checkShift() method and post call to the objectReset() method, which sets all object attributes to their initial state.
// post call to objectReset we expect all accessor method to return a value of 0 for integers and " " for strings.
//
// Assumptions: Driver assumes class will be utilized for its intended purporse of encryption followed by an interactive guessing game which provides statitical feedback. For the class to yield
// significant data from the object structure must be of the logical order laid out above. Driver also assumes any errors regarding data types will be handled on the application side. Although prompts
// indicating improper data has been provided will initiate on the class side, to preserve order in the application programmers must ensure a succesful encryption has been returned by encrypt(), prior
// to beginning a guessing game. Class design also expects a call to objectRest() or creation of a new object post guessing game if a new encryption and game is to take place. Again, this is necessary to
// provide integrety to the object's data in reflecting only the active game. For the purpose of this driver all input will be hard coded, not accepting user input, for the purpose of speed and testing.
// 

#include "EncryptWorld.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// create EncryptWorld object
	EncryptWorld ew;
	
	// Desciption: passing string of < 4 characters will result in return equal to argument and display error prompt
	// input: string under 4 characters
	// modify: after prompt for acceptable input we will assign a new value to the variable
	// expected output: prompt asking for a minimum of 4 characters displayed with a return value equal to passed string (unencrypted).
	// while loop to continue prompt until a string of 4 characters is provided, where variable will be assigned acceptable argument
	string phrase = "aaa";
	while (phrase == ew.encrypt(phrase)) {
		phrase = "aa bb cc xx yy zz AA BB CC XX YY ZZ";
	}

	// Description: Test acceptable argument.
	// input: acceptable string argument
	// modify: change to object's shift and phrase attribute
	// expect output: 12 pairs of characters in sequential sets of 3. 6 pairs lowercase and 6 pairs of an upppercase equivalent returned.  any value shifted beyond 'z' or 'Z' should 
	// wrap to beginning of alphabet. all blank spaces should be persistent. Shift is randomly generated and should uniformly shift output. 
	// change to object's shift and phrase attribute
	cout << ew.encrypt(phrase) << endl << endl;

	// Descriptioin: disable encryption
	// input: boolean
	// modify: change to object's "on" variable
	// output: none
	ew.encryptionOff(false);

	// Description: Test encryption is off
	// input: acceptable string
	// modify: no modification to object
	// output: return of original string and a prompt from class method stating encryption disabled
	ew.encrypt("is encryption off?");

	// for loop to determine if checkShift() method provides correct return values of passed argument in relation to "shift" value for all possible shift values.
	for (int i = 1; i < 10; i++) {

		// Description: test call to checkShift() method with acceptable argument
		// input: acceptable integer value
		// modify: changes to objects guessCount, totalGuessCount, lowGuessCount(possibly), highGuessCount(possibly), avgGuessCount attributes.
		// expect -1 returns prior to a return of 0 and return values of 1 post 0. 0 represents encryption key
		cout << "Guess: " << i << ": \t" << "Relative Value: " << ew.checkShift(i) << endl;

		// Description: test getHighGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect 0 return value pre encryption key, followed by an incremental return value post encryption key
		cout << "High Guess Count: \t" << ew.getHighGuessCount() << endl;

		// Description: test getLowGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect incremental return value pre encryption key and repeating value post encryption key
		cout << "Low Guess Count: \t" << ew.getLowGuessCount() << endl;

		// Descritpion: test getGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// ecpect incremental return value from 1 to 9
		cout << "Total Guess Count: \t" << ew.getGuessCount() << endl;

		// Description: test getTotalGuess() returns expected value
		// input: N/A
		// modify: N/A
		// expect an addition of passed value to prior value, with an ending value of 45
		cout << "Total Guess Count Sum: \t" << ew.getTotalGuess() << endl;

		//Description: test avgGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect an average between "total guess count sum" and "total guess count" with an ending value of 5.
		cout << "Average Guess Value: \t" << ew.getAvgGuess() << endl << endl;
	}

	// Descritpion: method will reset object to its initial state, clearing all guess statistics
	// input: N/A
	// Modify: All class attributes will be set to default
	// output: N/A
	ew.objectReset();

	// Description: Test objectReset() has brough object attribute to initial state
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getAvgGuess() << endl;

	// Description: Test objectReset() has brough object attribute to initial state
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getGuessCount() << endl;

	// Description: Test objectReset() has brough object attribute to initial state
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getHighGuessCount() << endl;

	// Description: Test objectReset() has brough object attribute to initial state
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getLowGuessCount() << endl;

	// Description: Test objectReset() has brough object attribute to initial state
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getTotalGuess() << endl;

	// Description: check that encrypt() is enabled and returns encrypted input.
	// input: acceptable string value
	// modify: object's phrase and shift attributes will be changed
	// output: expect output: 12 pairs of characters in sequential sets of 3. 6 pairs lowercase and 6 pairs of an upppercase equivalent returned.  any value shifted beyond 'z' or 'Z' should 
	// wrap to beginning of alphabet. all blank spaces should be persistent. Shift is randomly generated and should uniformly shift output. 
	cout << ew.encrypt("aa bb cc xx yy zz AA BB CC XX YY ZZ") << endl << endl;

	cout << "*********************************************************" << endl;

	// create a second EncryptWorld object
	EncryptWorld ew2;

	// Description: encrypt() will shift special characters and numbers without any wrapping.
	// input: an acceptable string
	// modify: objects phrase and shift attributes will change
	// output: return value of encrypted phrase.
	cout << ew2.encrypt("this is to test special characters 123 123 !@#$%^&*( ") << endl << endl;
	
	// Description: testing an implicit cast of character passed as integer. Expect prompt to enter an integer value between 1 and 9
	// input: Type char. will be implicityly cast
	// modify: n/a
	// output: method will return 2 and prompt user to input an integer between 1 and 9
	int testImplicitCast = 'a';
	ew2.checkShift(testImplicitCast);

	// Description: testing an integer argument above 9. 
	// input: integer above 9
	// modify: n/a
	// output: return 2, prompt user to input integer between 1 and 9
	ew.checkShift(10);

	// Description: testing an integer argument below 1. 
	// input: integer below 1
	// modify: n/a
	// output: return 2, prompt user to input integer between 1 and 9
	ew.checkShift(0);

	

	// Description Testing for implicit casting of doubles. expect i to be rounded down to integer, producing results identical to if i was assigned integer value.
	for (int i = 1.4; i < 10; i++) {

		// Description: test call to checkShift() method with double as argument
		// input: double value
		// modify: changes to objects guessCount, totalGuessCount, lowGuessCount(possibly), highGuessCount(possibly), avgGuessCount attributes.
		// expect -1 returns prior to a return of 0 and return values of 1 post 0. 0 represents encryption key
		cout << "Guess: " << i << ": \t" << "Relative Value: " << ew.checkShift(i) << endl;

		// Description: test getHighGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect 0 return value pre encryption key, followed by an incremental return value post encryption key
		cout << "High Guess Count: \t" << ew.getHighGuessCount() << endl;

		// Description: test getLowGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect incremental return value pre encryption key and repeating value post encryption key
		cout << "Low Guess Count: \t" << ew.getLowGuessCount() << endl;

		// Descritpion: test getGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// ecpect incremental return value from 1 to 9
		cout << "Total Guess Count: \t" << ew.getGuessCount() << endl;

		// Description: test getTotalGuess() returns expected value
		// input: N/A
		// modify: N/A
		// expect an addition of passed value to prior value, with an ending value of 45
		cout << "Total Guess Count Sum: \t" << ew.getTotalGuess() << endl;

		//Description: test avgGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect an average between "total guess count sum" and "total guess count" with an ending value of 5.
		cout << "Average Guess Value: \t" << ew.getAvgGuess() << endl << endl;
	}

	// Description: method to retrieve original phrase, pre encryption. 
	// input: n/a
	// modify: n/a
	// output: return value of "123 123 !@#$%^&*("
	cout << ew2.getPhrase();

	// for testing purposes... keep console window from exiting
	cin.get();
}
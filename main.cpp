// Author: Damien Sudol
// Filename: EncryptWorld P1
// Date: 09/28/2017
// Version: 1.0
//
// Desctription: Application driver will create EncryptWorld object with the objective of testing all accesible methods with a full spectrum of possible inputs, then comparing EncryptWorld.h  
// documentation, the expected results, with console output. The assumption is that this class when used in an application will take a phrase which will be encrypted, then prompt user to guess
// a value until, providing statistical feedback until they correctly provide the shift value used in encrypting their phrase. encryption will be disabled until the correct casesar shift is provided.
// object values will then be set to its initial state and encryption will be re-inabled.  No error checking will be provided by the EncryptWorld class; all error handling must be handeled on the application
// level to ensure proper input is provided to the class. For the purpose of this driver all inputs will be of the correct data type as per the EncryptWorld.h documentation. 


#include "EncryptWorld.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// create EncryptWorld object
	EncryptWorld ew;

	// expect output: 12 pairs of characters in sequential sets of 3. 6 pairs lowercase and 6 pairs of an upppercase equivalent returned.  any value shifted beyond 'z' or 'Z' should 
	// wrap to beginning of alphabet. all blank spaces should be persistent. Shift is randomly generated and should uniformly shift output. 
	cout << ew.encrypt("aa bb cc xx yy zz AA BB CC XX YY ZZ") << endl << endl;

	// disable encryption
	ew.encryptionOff(false);

	// test if encryption has been disabled; expected output "Sorry, encryption has been disabled."
	ew.encrypt("is encryption off?");

	// for loop to determine if checkShift() method provides correct return values of passed argument in relation to "shift" value for all possible shift values.
	for (int i = 1; i < 10; i++) {

		// expect -1 returns prior to a return of 0 and return values of 1 post 0. 0 represents encryption key
		cout << "Guess: " << i << ": \t" << "Relative Value: " << ew.checkShift(i) << endl;

		// expect 0 return value pre encryption key, followed by an incremental return value post encryption key
		cout << "High Guess Count: \t" << ew.getHighGuessCount() << endl;

		// expect incremental return value pre encryption key and repeating value post encryption key
		cout << "Low Guess Count: \t" << ew.getLowGuessCount() << endl;

		// ecpect incremental return value from 1 to 9
		cout << "Total Guess Count: \t" << ew.getGuessCount() << endl;

		// expect an addition of passed value to prior value, with an ending value of 45
		cout << "Total Guess Count Sum: \t" << ew.getTotalGuess() << endl;

		// expect an average between "total guess count sum" and "total guess count" with an ending value of 5.
		cout << "Average Guess Value: \t" << ew.getAvgGuess() << endl << endl;
	}

	// method will reset object to its initial state, clearing all guess statistics
	ew.objectReset();

	// expect a return of 0
	cout << ew.getAvgGuess() << endl;

	// expect a return of 0
	cout << ew.getGuessCount() << endl;

	// expect a return of 0
	cout << ew.getHighGuessCount() << endl;

	// expect a return of 0;
	cout << ew.getLowGuessCount() << endl;

	// expect a return of 0;
	cout << ew.getTotalGuess() << endl;

	// check that encrypt() is enabled and returns encrypted input.
	// expect output: 12 pairs of characters in sequential sets of 3. 6 pairs lowercase and 6 pairs of an upppercase equivalent returned.  any value shifted beyond 'z' or 'Z' should 
	// wrap to beginning of alphabet. all blank spaces should be persistent. Shift is randomly generated and should uniformly shift output. 
	cout << ew.encrypt("aa bb cc xx yy zz AA BB CC XX YY ZZ") << endl << endl;

	cin.get();
}

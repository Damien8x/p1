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

	EncryptWorld ew;

	string test = ew.encrypt("testing testing");

	cout << test << endl;

	ew.encryptionOff(false);

	test = ew.encrypt("testing teseting");


	cin >> test;



		 
	
}

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <Encryptor.h>


using namespace std;

int main() {
     Encryptor Encrypt; //Initializes an instance of the class Encryptor
	 string value;
     string fileName;
	while (value != "4")
	{
	    Encrypt.menu(); //Calls the basic menu
        getline(cin, value);
        int x = stoi(value);
		switch(x){
			case 1:
			    {
                    cout << "enter the name of the file" << endl;   //asks for user input
                    getline(cin, fileName);                         //takes name of file and then reads in the file
                    Encrypt.fileReader(fileName);
                    Encrypt.encryptionFunction();                   //after reading in the file and encrypting the file, it is then exported as a text file
                    //cout << "This is a test" << endl;
                    Encrypt.exportFile();
                    cout << "The encrypted file has now been exported" << endl;
                    break;
			    }
			case 2:
                {
                    Encrypt.encryptUserInput();        //function allows for users to input their own text
                    break;
                }
			case 3:
			    {
                    string stringKey;
                    getline(cin, stringKey);
                    //cout << "TEST 123" << endl;
                    int decryptKey = stoi(stringKey);
                    cout << "enter the name of the encrypted file" << endl;  //Asks for the name of the encrypted file
                    getline(cin, fileName);
                    Encrypt.fileReader(fileName);                            //reads in the encrypted file
                    Encrypt.decryptionFunction();                            //adds or subtracts the key
                    Encrypt.exportFile();                                    //exports the file
                    break;
			    }
            case 4:{
                cout<<"Goodbye!" << endl;                                     //ends the program
                break;
            }
            default: {
                cout << "Invalid Input" << endl;
            }

		}
	}

}

#include "Encryptor.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstring>

Encryptor::Encryptor()
{
    //ctor
}

Encryptor::~Encryptor()
{
    //dtor
}





void Encryptor::menu(){
	cout << "What would you like to do?" << endl;
	cout << "1: Read in a text file for encryption" << endl;
	cout << "2: Enter your own text for encryption" <<endl;
	cout << "3: Decrypt a file" << endl;
	cout << "4. Quit" << endl;
}

void Encryptor::encryptionMenu(){
	cout << "How would you like to encrypt you text?" << endl;
	cout << "1: add the key" << endl;
	cout << "2: subtract the key" <<endl;
}

void Encryptor::decryptionMenu(){
	cout << "How will you decrypt your text?" << endl;
	cout << "1: add the key" << endl;
	cout << "2: subtract the key" <<endl;
}

int Encryptor::keyGenerator(){
	//creates the key used for encryption
	int newKey = rand() % 15 + 1;
	return newKey;
}

void Encryptor::fileReader(string filename){
	ifstream file;
	file.open(filename);
	string line;
	if(file.is_open()){
        while(getline(file, line, ' ')){
            istringstream iss(line);
            string temporary;
                while(iss >> temporary){
                                            //call function that will take the string temporary and parse through it
                                            //and put every word into the linked list
                    LinkedList(temporary);
                }
        }
	}
	file.close();
}

void Encryptor::LinkedList(string word){
		node *x = new node;
		x = head;
		node *temp = new node;
		while (x->next!=NULL){
            x = x->next;
		}
		temp->collectionOfChars = word;
		x->next = temp;

}

void Encryptor::encryptionFunction(){
	encryptionMenu();
	node *temp = new node;
	temp = head;
	string value1;

	while (value1 != "2")
	{
        getline(cin, value1);
        while(value1 != "1" and value1 != "2"){
            cout<<"Please enter a valid option"<<endl;
            getline(cin, value1);
        }
        int x = stoi(value1);
		switch(x){
			case 1:
				//add key function
				addKey();
				cout << key << " was added to every letter." << endl;
				break;
			case 2:
				//subtract key function
				subtractKey();
				cout << key << " was subtracted from every letter." << endl;
				break;
			default:
				cout << "Invalid Input" << endl;
		}
		//cout << "Encryption TEST" << endl;
		break;

	}

}

void Encryptor::addKey(){
	string tempWord;
	node *temp1 = new node;
	temp1 = head;
	while(temp1 != NULL){
		tempWord = temp1->collectionOfChars;
		for(int i = 0; i<tempWord.size(); i++){
			tempWord[i] += key;
			if(tempWord[i] > 126){
                tempWord[i] - 94;
			}
			if(tempWord[i] < 32){
                tempWord[i]+= 32;
			}
		}
		temp1->collectionOfChars = tempWord;
		temp1 = temp1->next;
	}
}

void Encryptor::subtractKey(){
	string tempWord;
	node *temp = new node;
	temp = head;
	while(temp != NULL){
		tempWord = temp->collectionOfChars;
		for(int i = 0; i<tempWord.size(); i++){
			tempWord[i] = tempWord[i] - key;
			if(tempWord[i] < 32){
                tempWord[i]+= 32;
			}
            if(tempWord[i] > 126){
                tempWord[i] - 94;
			}
		}
		temp->collectionOfChars = tempWord;
		temp = temp->next;
	}
}


void Encryptor::exportFile(){
	node *temp2 = new node;
	temp2 = head;

	ofstream out ("New_File.txt");

	while(temp2 != NULL){
		out << temp2->collectionOfChars << " ";
		temp2 = temp2->next;
	}

	out.close();
}

void Encryptor::encryptUserInput(){
    cout << "Please enter the text that you want encrypted" << endl;
    string userInput;
    getline(cin,userInput);
    for(int i = 0; i < userInput.size(); i++){
        userInput[i] += key;
        cout << userInput[i]<< "";
    }
    cout << " " << endl;
    cout << key << " was added to every letter" << endl;
}

void Encryptor::decryptionFunction(){
	decryptionMenu();

	string value1;
	while (value1 != "3")
	{
        getline(cin, value1);
        int x = stoi(value1);

		switch(x){
			case 1:{
			    cout << "Please enter the key to the text."<<endl;
				string newKey;
                getline(cin, newKey);
                int decryptKey = stoi(newKey);
				addDecryptKey(decryptKey);
				cout << key << " was added to every letter." << endl;
				break;
			}
			case 2: {
				cout << "Please enter the key to the text."<<endl;;
				string newKey;
                getline(cin, newKey);
                int decryptKey = stoi(newKey);
				subtractDecryptKey(decryptKey);
				cout << key << " was subtracted from every letter." << endl;
				break;
			}
			default:
				cout << "Invalid Input" << endl;
		}
	}
}

void Encryptor::addDecryptKey(int decryptKey){
	string tempWord;
	int newKey = decryptKey;
	node *temp1 = new node;
	temp1 = head;
	while(temp1 != NULL){
		tempWord = temp1->collectionOfChars;
		for(int i = 0; i<tempWord.size(); i++){
			tempWord[i] += newKey;
			if(tempWord[i] > 126){
                tempWord[i] - 94;
			}
			if(tempWord[i] < 32){
                tempWord[i]+= 32;
			}
		}
		temp1->collectionOfChars = tempWord;
		temp1 = temp1->next;
	}
}

void Encryptor::subtractDecryptKey(int decryptKey){
	string tempWord;
	int newKey = decryptKey;
	node *temp = new node;
	temp = head;
	while(temp != NULL){
		tempWord = temp->collectionOfChars;
		for(int i = 0; i<tempWord.size(); i++){
			tempWord[i] = tempWord[i] - newKey;
			if(tempWord[i] < 32){
                tempWord[i]+= 32;
			}
            if(tempWord[i] > 126){
                tempWord[i] - 94;
			}
		}
		temp->collectionOfChars = tempWord;
		temp = temp->next;
	}
}


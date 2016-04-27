#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>

using namespace std;

 struct node{
            string collectionOfChars;
            node *next = NULL;
            node *previous = NULL;
        };

class Encryptor
{

    public:

        void menu();
        void encryptionMenu();
        int keyGenerator();
        void fileReader(std::string filename);
        void LinkedList(std::string word);
        void encryptionFunction();
        void addKey();
        void subtractKey();
        void exportFile();
        void encryptUserInput();
        void decryptionMenu();
        void decryptionFunction();
        void addDecryptKey(int decryptKey);
        void subtractDecryptKey(int decryptKey);

        Encryptor();
        ~Encryptor();
    protected:
    private:
         node *head = new node;
         int key = keyGenerator();


};

#endif // ENCRYPTOR_H

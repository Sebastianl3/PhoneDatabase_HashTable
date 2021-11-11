/*
    Title:  Driver.cpp
	Author:	Sebastian Ledford
	Purpose:  Puts the files together and runs the phone hash table menu.
*/
#include <iostream>
#include "HashTable.h"
#include "Phone.h"
#include <string>
#include <fstream>
using namespace std;

void InsertPhone(HashTable<Phone>*);
void printHashTable(HashTable<Phone>*);
void deletePhone(HashTable<Phone>*);
void searchPhone(HashTable<Phone>*);
void readPhonesFromFile(HashTable<Phone>*);

int main(){
    HashTable<Phone> *myTable = new HashTable<Phone>(10);
    int menuChecker = 0;
    int menuSelector = 0;

    do {
        
        while (menuSelector != 6)
        {
            cout << endl;
            cout << "Phone Management Menu:" << endl << endl;
            cout << "1. Add Phone(s) from File\n";
            cout << "2. Add Phone Manually\n";
            cout << "3. Search For Phone\n";
            cout << "4. Delete A Phone\n";
            cout << "5. Print Hash Table\n";
            cout << "6. End Program\n";
            cout << "Choose 1-6:    ";

            cin >> menuSelector;
            cout << endl;

            if (menuSelector == 1)
            {
                readPhonesFromFile(myTable);  // add phone from File
            }
            else if (menuSelector == 2)
            {
               InsertPhone(myTable); // add phone manually
            }
            else if (menuSelector == 3)
            {
                searchPhone(myTable); // search for phone
            }
            else if (menuSelector == 4)
            {
                deletePhone(myTable);// Delete a phone
            }
            else if (menuSelector == 5)
            {
                printHashTable(myTable); // Print Hast table
            }
            else if (menuSelector == 6)
            {
                cout << "\n\nGOODBYE!!";
                menuChecker = 1;
            }
        }
    } while (menuChecker == 0);
}

void InsertPhone(HashTable<Phone> *myTable){
    int temp1;
    string temp2;
    float temp3;
    
    cout << "\nInsert phone id Number (key):  ";
    cin >> temp1;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid key. Must be an integer.\n";
        cout << "\nInsert phone id Number (key):  ";
        cin >> temp1;
    }

    cout << "\nInsert phone name:       ";
    cin.ignore();
    getline(cin, temp2);

    cout << "\nInsert phone price:      ";
    cin >> temp3;

    Phone* phoneInput = new Phone(temp1, temp2, temp3);

	myTable->putValue(temp1, *phoneInput);
}

void printHashTable(HashTable<Phone> *myTable)
{
    myTable->printHashTable();
}

void deletePhone(HashTable<Phone> *myTable)
{
   cout << "This is following list of phones: \n";
   printHashTable(myTable);
   int Destroyer;
   cout << "Which phone would you like to remove, enter Id Number:  ";
   cin >> Destroyer;
   myTable->removeValue(Destroyer);
}

void searchPhone(HashTable<Phone> *myTable)
{
    int key;
    cout << "What is the key for the phone you are looking for?\n";
    cin >> key;
    cout << endl;
    (myTable->getValue(key)).printPhone();
}

void readPhonesFromFile(HashTable<Phone> *myTable)
{
    fstream inFile;
	char temp[100];
    string fileName;
    int temp1;
    string temp2;
    float temp3;
    Phone* onePhone;
    inFile.open("dataFile.txt");
    if(inFile.good())
    {
        inFile >> temp1;
        while(!inFile.eof())
        {
            inFile.ignore();
            inFile.getline(temp, 100);
            temp2 = temp;
            inFile >> temp3;
           
            onePhone = new Phone(temp1, temp2, temp3);
            myTable->putValue(temp1, *onePhone);
            cout << "Entering phone with ID " << temp1 << " and name " << temp2 << endl << endl;
            inFile >> temp1;
        }
    }
}

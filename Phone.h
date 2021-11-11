#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>
using namespace std;

class Phone
{
	private:
		int idNum; 
		string phoneName;
		float price;
		
	public:
		Phone(int idNum, string name, float price){
			this->idNum = idNum;
			this->phoneName = name;
			this->price = price;
		}
		Phone(){
			this->idNum = 0;
			this->phoneName = "EMPTY";
			this->price = 0;
		}
		int getidNum() const;
		string getphoneName() const;
		float getPrice() const;
		friend ostream & operator<< (ostream & os, Phone c);
		void printPhone()
		{
			if (this->phoneName == "EMPTY")
			{
				cout << "There is no key that matches a phone in the table \n\n";
			}
			else
			{
			cout << "idNum: 	 " << this->idNum << endl;
			cout << "Phone name: " << this->phoneName << endl;
			cout << "Price: 	$" << this->price << endl << endl;
			}
		}

		
};

#endif
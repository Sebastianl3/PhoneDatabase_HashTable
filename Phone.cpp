		#include "Phone.h"
        
        int Phone::getidNum() const
		{
			return this->idNum;
		}
		
        string Phone::getphoneName() const
		{
			return this->phoneName;
		}
		
        float Phone::getPrice() const
		{
			return this->price;
		}
		
        ostream & operator<< (ostream & os, Phone c)
		{
			os << c.getidNum() << ", " << c.getphoneName();
			return os;
		}
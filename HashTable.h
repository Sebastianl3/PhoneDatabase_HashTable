/*
	Title:  HashTable.h
	Author:	Sebastian Ledford
	Purpose:  	Hash Table Implementation
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
#include <string>
using namespace std;

template <typename T>
class HashTable
{
	private:
		int tableSize;
		HashEntry<T>** hashArray;
		
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry<T>*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry<T> *prevEntry = NULL;
					HashEntry<T> *entry = hashArray[i];
					while(entry != NULL)
					{
						prevEntry = entry;
						entry = entry->getNext();
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
		}
		T getValue(int key);
		void putValue(int key, T value);
		void removeValue(int key);
		void printHashTable();
};
		
		template<typename T>
		T HashTable<T>::getValue(int key)
		{
			T empty;
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] == NULL)
			{	
				return empty;
			}
			else
			{
				HashEntry <T>*entry = hashArray[bucketIndex];
				while(entry != NULL && entry->getKey() != key)
					entry = entry->getNext();
				if(entry == NULL)
					return empty;
				else
					return entry->getValue();
			}
		}
		
		template<typename T>
		void HashTable<T>::putValue(int key, T value)
		{
			int bucketIndex = key % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			if(hashArray[bucketIndex] == NULL) //no collision
			{
				hashArray[bucketIndex] = new HashEntry<T>(key, value);
			}
			else //collision
			{
				HashEntry<T>* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry<T>(key, value));
			}
		}
		
		template<typename T>
		void HashTable<T>::removeValue(int key)
		{
			HashEntry<T> *entry;
			HashEntry<T> *prevEntry;
			int bucketIndex = key% tableSize;
			if(hashArray[bucketIndex] != NULL)
			{
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while((entry->getNext() != NULL) & (entry->getKey() != key))
				{
					prevEntry = entry;
					entry = entry->getNext();
				}
				if(entry->getKey() == key) 
				{
					if(prevEntry == NULL)
					{
						HashEntry<T> *nextEntry = entry->getNext();
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
						cout << "Id Number " << key << " has been deleted\n";
					}
					else
					{
						HashEntry<T> *next = entry->getNext();
						delete entry;
						prevEntry->setNext(next);
						cout << "Id Number " << key << " has been deleted\n";
					}
				}
			}		
			else{
				cout << "ID number " << key << " doesn't exist, no item deleted\n";
			}
		}
		
		template<typename T>
		void HashTable<T>::printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				cout << "BUCKET " << i;
				if(hashArray[i] != NULL)
				{
					HashEntry<T>* entry = hashArray[i];
					while(entry->getNext() != NULL)
					{
						cout << "---->" << setw(8) << entry->getValue();
						entry = entry->getNext();
					}
					cout << "---->" << setw(8) << entry->getValue();
					cout << "\n";
				}
				else
					cout << setw(8) << -1 << "\n";
			}
			cout << "----------\n\n";
		}
	


#endif
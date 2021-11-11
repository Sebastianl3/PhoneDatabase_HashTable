
#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class HashEntry
{
	private:
		int key;
		T value;
		HashEntry* next;
		
	public:
		HashEntry(int k, T v)
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		int getKey();
		T getValue();
		HashEntry* getNext();
		void setNext(HashEntry *next);
		void setValue(T v);
};
		
		template<typename T>
		int HashEntry<T>::getKey()
		{
			return key;
		}
		
		template<typename T>
		T HashEntry<T>::getValue()
		{
			return value;
		}
		
		template<typename T>
		HashEntry<T>* HashEntry<T>::getNext()
		{
			return next;
		}
		
		template<typename T>
		void HashEntry<T>::setNext(HashEntry *next)
		{
			this->next = next;
		}
		
		template<typename T>
		void HashEntry<T>::setValue(T v)
		{
			value = v;
		}


#endif
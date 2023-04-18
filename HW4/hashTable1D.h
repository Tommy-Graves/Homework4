#pragma once
#include <iostream>

using namespace std; 

class hashTable1D
{
	public:
		hashTable1D();
		int Insert(int*);

		int Find(int*);
		int Remove(int*);

		int GetLength();
		void Print();

		~hashTable1D();
	private:
		int** arr;
		int items;
		int hash(int*);
		int size = 500;
};


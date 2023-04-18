#pragma once
class hashTable2D
{
public:
	hashTable2D();
	~hashTable2D();

	void Insert(int*);
	int* Find(int);
	int Remove(int*);

	void Print();
private:
	int rows = 100;
	int cols = 5;
	int** arr;
};


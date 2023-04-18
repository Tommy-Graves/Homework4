#include "hashTable1D.h"

int main() {
	hashTable1D myTable = hashTable1D();

	int* ptr1 = new int(3);
	int* ptr2 = new int(1);
	int* ptr3 = new int(3);

	myTable.Insert(ptr1);
	myTable.Insert(ptr2);
	myTable.Insert(ptr3);

	myTable.Print();
}
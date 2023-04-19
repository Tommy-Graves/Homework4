#include "hashTable1D.h"
#include "hashTable2D.h"

int main() {
	hashTable2D myTable = hashTable2D();

	int* ptr1 = new int(3);
	int* ptr2 = new int(1);
	int* ptr3 = new int(3);

	myTable.Insert(ptr1);
	myTable.Insert(ptr2);
	myTable.Insert(ptr3);

	myTable.Print();
}
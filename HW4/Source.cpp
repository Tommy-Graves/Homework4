#include "hashTable1D.h"
#include <cstdlib>
#include <algorithm>

void shuffle_array(int arr[], int n);

int main() {
	hashTable1D myTable = hashTable1D();

	int range[100];

	for (int i = 0; i < 100; i++) {
		range[i] = i;
	}

	shuffle_array(range, 100);

	int* ptr1 = new int(3);
	int* ptr2 = new int(1);
	int* ptr3 = new int(3);
	int* ptr4 = new int(7);

	myTable.Insert(ptr1);
	myTable.Insert(ptr2);
	myTable.Insert(ptr3);

	int x = myTable.Find(ptr3);
	int y = myTable.Remove(ptr2);
	int d = myTable.Find(ptr4);
	int z = myTable.Remove(ptr4);

	
	cout << "looking for -1: " << d << endl;
}

void shuffle_array(int arr[], int n) {
	unsigned seed = 0;
	random_shuffle(arr, arr + n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
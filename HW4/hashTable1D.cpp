#include "hashTable1D.h"

hashTable1D::hashTable1D() {
	items = 0;
	arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = nullptr;
	}
}

int hashTable1D::hash(int* inVal) {
	return(*inVal % size);
}

int hashTable1D::Insert(int* inVal) {
	if (items == size) {
		cout << "The table is full" << endl;
		return -1;
	}
	int ret = 1;
	int address = hash(inVal);
	if (arr[address] == nullptr) {	// covers inserting with no collisions
		arr[address] = inVal;
		return ret;
	}
	else {
		while (arr[address] != nullptr) { // while loop iterates until it finds a nullptr where inval can be inserted
			address++;
			ret++;
		}
		arr[address] = inVal;
		return ret;
	}
}

int hashTable1D::Find(int* inVal) {
	int ret = 1;
	int address = hash(inVal);

	if (arr[address] != nullptr && *arr[address] == *inVal) {	// found without collisions
		return ret;
	}
	else {
		
	}
}

int hashTable1D::GetLength() {
	return items;
}
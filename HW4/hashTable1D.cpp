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
		items++;
		return ret;
	}
	else {
		while (arr[address] != nullptr) { // while loop iterates until it finds a nullptr where inval can be inserted
			address++;
			ret++;
		}
		arr[address] = inVal;
		items++;
		return ret;
	}
}

int hashTable1D::Find(int* inVal) {
	if (items == 0) {	// searching in an empty table
		return -1;
	}

	int ret = 1;
	int address = hash(inVal);

	if (arr[address] != nullptr){// found without collisions
		if (*arr[address] == *inVal) {
			return ret;
		}
	}
	else {
		while (arr[address] != nullptr) {
			if (*arr[address] == *inVal) {
				return ret;
			}
			ret++;
			address++;
			if (address >= size) {
				return -1;
			}
		}
		return -1;
	}
}

int hashTable1D::Remove(int* inVal) {
	int address = hash(inVal);
	int ret = 1;

	if (arr[address] != nullptr) { // inVal found with no collision
		if (*arr[address] == *inVal) {
			delete arr[address];
			arr[address] = nullptr;
			return ret;
		}
	}
	else {
		while (arr[address] != nullptr) {
			if (*arr[address] == *inVal) {
				delete arr[address];
				arr[address] = nullptr;
				return ret;
			}
			ret++;
			address++;
			if (address >= size) {
				return -1;
			}
		}
		return -1;
	}
}

void hashTable1D::Print() {
	for (int i = 0; i < size; i++) {
		if (arr[i] == nullptr) {
			cout << "___" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << "\\| /" << endl;
			cout << " \\/" << endl;
		}
		else if(i != size - 1){
			cout << *arr[i] << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << "\\| /" << endl;
			cout << " \\/" << endl;
		}
		else if(arr[i] == nullptr && i == (size - 1)) {
			cout << "___" << endl;
		}
		else if (arr[i] != nullptr && i == (size - 1)) {
			cout << *arr[i] << endl;
		}
	}
}

int hashTable1D::GetLength() {
	return items;
}

hashTable1D::~hashTable1D() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
}
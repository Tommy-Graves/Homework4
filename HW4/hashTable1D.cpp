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
		while (ret < size) {	// iterates until every spot is checked
			if (arr[address] == nullptr) {
				ret++;
				if (address < size) {
					address++;
				}
				else if (address == size) {
					address = 0;
				}
			}
			else {
				if (*arr[address] == *inVal) {
					ret++;
					return ret;
				}
				ret++;
				address++;
			}
		}
		if (arr[address] == nullptr) {	// leaves while loop and last item is nullptr
			return -1;
		}
		else if(*arr[address] == *inVal) {	// leaves while loop and last item equals inVal
			ret++;
			return ret;
		}
		else {	// leaves while loop and last item does not equal inVal
			return -1;
		}
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
		while (ret < size) {
			while (arr[address] == nullptr) {	// iterates until it finds a spot that isnt null
				ret++;
				if (address < size) {
					address++;
				}
				else if (address == size) {
					address = 0;
				}
			}
			if (*arr[address] == *inVal) {
				ret++;
				delete arr[address];
				arr[address] = nullptr;
				return ret;
			}
			else if (*arr[address] != *inVal) {
				ret++;
				address++;
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
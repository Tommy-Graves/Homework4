#include "hashTable2D.h"
hashTable2D::hashTable2D() {
	arr = new int**[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int*[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = nullptr;
		}
	}
}

hashTable2D::~hashTable2D() {
	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 0; j--) {
			delete arr[i][j];
		}
	}
}
int hashTable2D::hash(int* inVal) {
	return (*inVal % rows);
}
int hashTable2D::Insert(int* inVal) {
	if (items == (rows * cols)) {
		cout << "The hash table is full" << endl;
		return -1;
	}
	int ret = 1;
	int address = hash(inVal);
	if (arr[address][0] == nullptr) {
		arr[address][0] == inVal;
		return ret;
	}
	else {
		int i = 1;
		while (arr[address][i] != nullptr) {
			i++;
			ret++;
			if (i == 5) {
				i = 0;
				address++;
			}
		}
		arr[address][i] = inVal;
		return ret;
	}
}
int hashTable2D::Find(int* inVal) {
	int ret = 1;
	int address = hash(inVal);
	int i = 0;
	if (arr[address][i] != nullptr && *arr[address][i] == *inVal) {
		return ret;
	}
	else {
		if (arr[address][i] == nullptr) {
			cout << "Item not in hash table" << endl;
			return -1;
		}
		while (*arr[address][i] != *inVal) {
			ret++;
			i++;
			if (i == 5) {
				i = 0;
				address++;
			}
			if (arr[address][i] == nullptr) {
				cout << "Item not in hash table" << endl;
				return -1;
			}
		}
		return ret;
	}

}
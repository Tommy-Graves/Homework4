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
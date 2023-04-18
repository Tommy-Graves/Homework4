#include "hashTable2D.h"
hashTable2D::hashTable2D() {
	int ** arr = new (int*)[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new (int**)[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = nullptr;
		}
	}
}
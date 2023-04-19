#pragma once
#include <iostream>
using namespace std;
class BST
{
private:
	struct node {
		int data;
		node* right;
		node* left;
	};
	node* root;
public:
	BST();
	BST(int);

	int Insert(int);
	int Find(int);
	int Remove(int);

	void print2DUtil(node*, int);
	void print2D(node*);
};


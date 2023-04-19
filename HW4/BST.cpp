#include "BST.h"
#define COUNT 10
BST::BST() {
    root = nullptr;
}
BST::BST(int inVal) {
    node* newNode = new node();
    newNode->data = inVal;
    newNode->left = nullptr;
    newNode->right = nullptr;
    root = newNode;
}

int BST::Insert(int inVal) {
    int ret = 1;
    if (root == nullptr) {
        node* newNode = new node();
        newNode->data = inVal;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root = newNode;
        return ret;
    }
    node* temp = root;
    while (1 == 1) {
        if (inVal > temp->data && temp->right != nullptr) {
            ret++;
            temp = temp->right;
        }
        else if (inVal <= temp->data && temp->left != nullptr) {
            ret++;
            temp = temp->left;
        }
        else if (inVal > temp->data && temp->right == nullptr) {
            ret++;
            node* newNode = new node();
            newNode->data = inVal;
            newNode->left = nullptr;
            newNode->right = nullptr;
            temp->right = newNode;
            return ret;
        }
        else if (inVal <= temp->data && temp->left != nullptr) {
            ret++;
            node* newNode = new node();
            newNode->data = inVal;
            newNode->left = nullptr;
            newNode->right = nullptr;
            temp->left = newNode;
            return ret;
        }
    }
}
int BST::Find(int inVal) {
    int ret = 1;
    if (root == nullptr) {
        cout << "Not in tree" << endl;
        return -1;
    }
    node* temp = root;
    while (1 == 1) {
        if (temp->data == inVal) {
            return ret;
        }
        else if (inVal > temp->data && temp->right != nullptr) {
            ret++;
            temp = temp->right;
        }
        else if (inVal <= temp->data && temp->left != nullptr) {
            ret++;
            temp = temp->left;
        }
        else if (inVal > temp->data && temp->right == nullptr) {
            cout << "Not in tree" << endl;
            return -1;
        }
        else if (inVal <= temp->data && temp->left != nullptr) {
            cout << "Not in tree" << endl;
            return -1;
        }
    }
}
int BST::Remove(int inVal) {
    int ret = 1;
    if (root == nullptr) {
        cout << "Not in tree" << endl;
        return -1;
    }
    node* temp = root;
    node* conTemp = temp;
    while (1 == 1) {
        if (temp->data == inVal) {
            if (inVal > temp->data) {
                if (temp->right == nullptr && temp->left == nullptr) {
                    ret++;
                    delete temp;
                    conTemp->right = nullptr;
                    return ret;
                }
                else if (temp->right != nullptr && temp->left == nullptr) {
                    ret++;
                    conTemp->right = temp->right;
                    delete temp;
                    return ret;
                }
                else if (temp->right == nullptr && temp->left != nullptr) {
                    ret++;
                    conTemp->right = temp->left;
                    delete temp;
                    return ret;
                }
                else {
                    node* temp2 = temp;
                    while (temp2->right->right != nullptr) {
                        ret++;
                        temp2 = temp2->right;
                    }
                    temp->data = temp2->right->data;
                    delete temp2->right;
                    temp2->right = nullptr;
                    return ret;
                }
            }
            else {
                if (temp->right == nullptr && temp->left == nullptr) {
                    ret++;
                    delete temp;
                    conTemp->right = nullptr;
                    return ret;
                }
                else if (temp->right != nullptr && temp->left == nullptr) {
                    ret++;
                    conTemp->right = temp->right;
                    delete temp;
                    return ret;
                }
                else if (temp->right == nullptr && temp->left != nullptr) {
                    ret++;
                    conTemp->right = temp->left;
                    delete temp;
                    return ret;
                }
                else {
                    node* temp2 = temp;
                    while (temp2->left->left != nullptr) {
                        ret++;
                        temp2 = temp2->left;
                    }
                    temp->data = temp2->left->data;
                    delete temp2->left;
                    temp2->left = nullptr;
                    return ret;
                }
            }
            return ret;
        }
        else if (inVal > temp->data && temp->right != nullptr) {
            ret++;
            conTemp = temp;
            temp = temp->right;
        }
        else if (inVal <= temp->data && temp->left != nullptr) {
            ret++;
            conTemp = temp;
            temp = temp->left;
        }
        else if (inVal > temp->data && temp->right == nullptr) {
            cout << "Not in tree" << endl;
            return -1;
        }
        else if (inVal <= temp->data && temp->left != nullptr) {
            cout << "Not in tree" << endl;
            return -1;
        }
    }
}
void BST::print2DUtil(node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Process left child
    print2DUtil(root->left, space);
}
void BST::print2D(node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
#include <iostream>
using namespace std;

//struktur node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Constructor untuk mempermudah pembuatan node baru
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Fungsi untuk memasukkan angka ke tree (sesuai soal)
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

//fungsi yang cetak angka dari root->left->right
void preOrder(Node* root) {
    if (root == NULL) return;
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//Tempat input data
int main() {
    Node* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    insert(root, 6);

    cout << "Output: ";
    preOrder(root);
    cout << endl;

    return 0;
}
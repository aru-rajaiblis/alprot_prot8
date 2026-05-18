#include <iostream>

using namespace std;

//Bahan pembentuk cabang tree
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

//fungsi yang memasukkan angka ke tree
BSTNode* Insertnode (BSTNode* root, int data){
    //angka dimasukkan ke node yang kosong
    if (root == nullptr){
        BSTNode* newnode = new BSTNode();
        newnode->data = data;
        newnode->left = newnode->right = nullptr;
        return newnode;
    }

    //aturan utama BST
    if (data < root->data){
        root->left = Insertnode(root->left, data);
    }
    else if(data > root->data){
        root->right = Insertnode(root->right, data);
    }
    return root;
}

//fungsi yang cetak angka dari root->left->right
void preorder(BSTNode* root) {
    if (root == nullptr) 
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    BSTNode* root = nullptr; //inisialisasi kalau kosong
    int data[] = {4, 7, 2, 3, 1, 6, 7};
    
    //agar loop otomatis tanpa ubah manual
    int n = sizeof(data) / sizeof(data[0]);
    //loop memasukkan data array ke setiap node
    for(int i = 0; i < n; i++) {
        root = Insertnode(root, data[i]);
    }

    cout << "Output :" << endl;
    preorder(root);
    
    return 0;
}
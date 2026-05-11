#include <iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* kiri;
    BSTNode* kanan;
};

//fungsi dasarnya bst
BSTNode* Insertnode (BSTNode* root, int data){
    if (root == nullptr){
        BSTNode* nodebaru = new BSTNode();
        nodebaru->data = data;
        nodebaru->kiri = nodebaru->kanan = nullptr;
        return nodebaru;
    }
    if (data <= root->data){
        root->kiri = Insertnode(root->kiri, data);
    }
    else{
        root->kanan = Insertnode(root->kanan, data);
    }
    return root;
}
   
void preorder(BSTNode* root) {
    if (root == nullptr) 
        return;

    cout << root->data << " ";
    preorder(root->kiri);
    preorder(root->kanan);
}

int main() {
    BSTNode* root = nullptr;
    int data[] = {4, 2, 7, 1, 3, 6};
    
    for(int i = 0; i < 6; i++) {
        root = Insertnode(root, data[i]);
    }

    cout << "Output :" << endl;
    preorder(root);
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int x, string path = "Root"){
    if(root == nullptr){
        cout << "Path : " << path << endl;
        return new Node(x);
    }
    if(root->data == x) {
        cout << "Element already exists.\n";
        cout << "Path: " << path << endl;
        return root;
    }
    if(x < root->data) {
        root->left = insert(root->left, x, path + "->Left");
    }
    else {
        root->right = insert(root->right, x, path + "->Right");
    }
    return root;
}

void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Insert tree size : ";
    int size;
    cin >> size;
    Node* root = nullptr;

    for(int i = 0 ; i < size; i++) {
        int x;
        cout << "Enter element : ";
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder traversal: \n";
    inorder(root);

    return 0;
}
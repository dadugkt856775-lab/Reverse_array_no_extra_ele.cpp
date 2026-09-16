#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int height;
    Node *left, *right;

    Node(int x) {
        key = x;
        height = 1;
        left = right = nullptr;
    }
};

int height(Node* root) {
    return root ? root->height : 0;
}

int balanceFactor(Node* root) {
    return root ? height(root->left) - height(root->right) : 0;
}

void updateHeight(Node* root) {
    root->height =
        1 + max(height(root->left),
                height(root->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    updateHeight(root);

    int balance = balanceFactor(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << "AVL Tree Inorder: ";
    inorder(root);

    return 0;
}

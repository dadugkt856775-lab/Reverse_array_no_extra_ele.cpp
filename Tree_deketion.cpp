#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* insertNode(Node* root, int x) {
    if (!root)
        return new Node(x);

    if (x < root->data)
        root->left = insertNode(root->left, x);
    else
        root->right = insertNode(root->right, x);

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int x) {
    if (!root)
        return nullptr;

    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    }
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }

    int value;
    cin >> value;

    root = deleteNode(root, value);

    cout << "After Deletion: ";
    inorder(root);

    return 0;
}

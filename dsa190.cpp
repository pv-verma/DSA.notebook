// BST Insert, Search and Inorder

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);
    return root;                       // equal keys are ignored
}

bool search(TreeNode* root, int key) {
    while (root != nullptr) {
        if (key == root->val) return true;
        root = (key < root->val) ? root->left : root->right;
    }
    return false;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    TreeNode* root = nullptr;
    for (int v : vals) root = insert(root, v);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Search 60: " << (search(root, 60) ? "Found" : "Not Found") << endl;
    cout << "Search 65: " << (search(root, 65) ? "Found" : "Not Found") << endl;

    freeTree(root);
    return 0;
}
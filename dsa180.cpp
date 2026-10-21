// Binary Tree Inorder Traversal and Height (Recursion)

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);                 // children first, then the node itself
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Height: " << height(root) << endl;

    freeTree(root);
    return 0;
}
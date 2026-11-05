// Lowest Common Ancestor of a Binary Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;

    TreeNode* l = lca(root->left, p, q);
    TreeNode* r = lca(root->right, p, q);

    if (l && r) return root;     // p and q were found on different sides
    return l ? l : r;            // both are on one side (or only one exists)
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;                  // node 5
    TreeNode* q = root->right;                 // node 1
    TreeNode* r = root->left->right->right;    // node 4

    cout << "LCA(5, 1) = " << lca(root, p, q)->val << endl;
    cout << "LCA(5, 4) = " << lca(root, p, r)->val << endl;

    freeTree(root);
    return 0;
}
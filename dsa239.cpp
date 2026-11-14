// Diameter of a Binary Tree

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int height(TreeNode* r, int& best) {
    if (r == nullptr) return 0;

    int l = height(r->left, best);
    int rt = height(r->right, best);

    best = max(best, l + rt);          // longest path that bends at this node
    return 1 + max(l, rt);
}

int diameter(TreeNode* root) {
    int best = 0;
    height(root, best);
    return best;
}

void freeTree(TreeNode* r) {
    if (r == nullptr) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameter(root) << endl;

    freeTree(root);
    return 0;
}
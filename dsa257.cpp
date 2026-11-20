// Symmetric Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool mirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    return a->val == b->val &&
           mirror(a->left, b->right) &&      // outer pair
           mirror(a->right, b->left);        // inner pair
}

bool isSymmetric(TreeNode* root) {
    return root == nullptr || mirror(root->left, root->right);
}

void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(2);
    t2->left->right = new TreeNode(3);
    t2->right->right = new TreeNode(3);

    cout << (isSymmetric(t1) ? "Symmetric" : "Not symmetric") << endl;
    cout << (isSymmetric(t2) ? "Symmetric" : "Not symmetric") << endl;

    freeTree(t1);
    freeTree(t2);
    return 0;
}
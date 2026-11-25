// Binary Tree Maximum Path Sum

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int gain(TreeNode* r, int& best) {
    if (!r) return 0;

    int l = max(0, gain(r->left, best));      // a negative branch is better dropped
    int rt = max(0, gain(r->right, best));

    best = max(best, l + rt + r->val);        // path that bends at this node
    return r->val + max(l, rt);               // only one side can continue upward
}

int maxPathSum(TreeNode* root) {
    int best = INT_MIN;
    gain(root, best);
    return best;
}

void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    TreeNode* a = new TreeNode(-10);
    a->left = new TreeNode(9);
    a->right = new TreeNode(20);
    a->right->left = new TreeNode(15);
    a->right->right = new TreeNode(7);

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);

    TreeNode* c = new TreeNode(-3);

    cout << maxPathSum(a) << endl;
    cout << maxPathSum(b) << endl;
    cout << maxPathSum(c) << endl;

    freeTree(a); freeTree(b); freeTree(c);
    return 0;
}
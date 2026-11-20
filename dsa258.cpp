// Build a Tree From Preorder and Inorder

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& pre, int& idx, int lo, int hi,
                unordered_map<int, int>& pos) {
    if (lo > hi) return nullptr;

    int v = pre[idx++];                     // preorder: next unused value is the root
    TreeNode* node = new TreeNode(v);
    int m = pos[v];                         // where the root sits in inorder

    node->left = build(pre, idx, lo, m - 1, pos);    // left subtree must be built first
    node->right = build(pre, idx, m + 1, hi, pos);
    return node;
}

void postorder(TreeNode* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << " ";
}

void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};

    unordered_map<int, int> pos;
    for (int i = 0; i < (int)in.size(); i++) pos[in[i]] = i;

    int idx = 0;
    TreeNode* root = build(pre, idx, 0, in.size() - 1, pos);

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    freeTree(root);
    return 0;
}
// Kth Smallest in a BST (Iterative Inorder)

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;

    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {          // go as far left as possible
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();

        if (--k == 0) return cur->val;    // nodes pop in sorted order
        cur = cur->right;
    }
    return -1;                            // k was larger than the tree size
}

void freeTree(TreeNode* r) {
    if (r == nullptr) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    cout << kthSmallest(root, 3) << endl;
    cout << kthSmallest(root, 1) << endl;

    freeTree(root);
    return 0;
}
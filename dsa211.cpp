// Morris Inorder Traversal (O(1) Space)

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void morrisInorder(TreeNode* root) {
    TreeNode* cur = root;

    while (cur != nullptr) {
        if (cur->left == nullptr) {
            cout << cur->val << " ";
            cur = cur->right;
        } else {
            TreeNode* pre = cur->left;                 // find the inorder predecessor
            while (pre->right != nullptr && pre->right != cur) pre = pre->right;

            if (pre->right == nullptr) {
                pre->right = cur;                      // temporary thread back to cur
                cur = cur->left;
            } else {
                pre->right = nullptr;                  // second visit: remove the thread
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
    cout << endl;
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    morrisInorder(root);

    freeTree(root);
    return 0;
}
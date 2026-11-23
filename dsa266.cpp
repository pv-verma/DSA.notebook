// Delete a Node From a BST

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* r, int k) {
    if (!r) return new TreeNode(k);
    if (k < r->val) r->left = insert(r->left, k);
    else r->right = insert(r->right, k);
    return r;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {                    // zero or one child: lift the other side
            TreeNode* r = root->right;
            delete root;
            return r;
        }
        if (!root->right) {
            TreeNode* l = root->left;
            delete root;
            return l;
        }
        TreeNode* s = root->right;            // two children: use the inorder successor
        while (s->left) s = s->left;
        root->val = s->val;
        root->right = deleteNode(root->right, s->val);
    }
    return root;
}

void inorder(TreeNode* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    TreeNode* root = nullptr;
    int vals[] = {5, 3, 6, 2, 4, 7};
    for (int v : vals) root = insert(root, v);

    root = deleteNode(root, 3);
    inorder(root); cout << endl;

    root = deleteNode(root, 5);
    inorder(root); cout << endl;

    root = deleteNode(root, 99);
    inorder(root); cout << endl;

    freeTree(root);
    return 0;
}
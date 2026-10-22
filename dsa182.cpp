// Level Order Traversal (Tree + Queue)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();          // nodes in the current level
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    for (auto& level : levelOrder(root)) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }

    freeTree(root);
    return 0;
}
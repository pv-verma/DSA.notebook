// Path Sum II (All Root-to-Leaf Paths)

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* r, int remaining, vector<int>& path, vector<vector<int>>& res) {
    if (!r) return;

    path.push_back(r->val);
    remaining -= r->val;

    if (!r->left && !r->right && remaining == 0) res.push_back(path);   // only leaves count

    dfs(r->left, remaining, path, res);
    dfs(r->right, remaining, path, res);
    path.pop_back();                                                    // undo on the way up
}

void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> res;
    vector<int> path;
    dfs(root, 22, path, res);

    for (auto& p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }

    freeTree(root);
    return 0;
}
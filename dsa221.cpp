// Serialize and Deserialize a Binary Tree

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void serialize(TreeNode* root, ostringstream& out) {
    if (root == nullptr) {
        out << "# ";                        // marker for a missing child
        return;
    }
    out << root->val << " ";
    serialize(root->left, out);
    serialize(root->right, out);
}

TreeNode* deserialize(istringstream& in) {
    string tok;
    if (!(in >> tok) || tok == "#") return nullptr;

    TreeNode* node = new TreeNode(stoi(tok));
    node->left = deserialize(in);           // same order as serialize: root, left, right
    node->right = deserialize(in);
    return node;
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    ostringstream out;
    serialize(root, out);
    string s = out.str();
    cout << "Serialized: " << s << endl;

    istringstream in(s);
    TreeNode* copy = deserialize(in);

    cout << "Inorder of rebuilt tree: ";
    inorder(copy);
    cout << endl;

    freeTree(root);
    freeTree(copy);
    return 0;
}
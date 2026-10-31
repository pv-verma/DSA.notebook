// Trie (Prefix Tree)

#include <iostream>
#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* child[26] = {nullptr};
        bool isEnd = false;
        ~Node() {
            for (int i = 0; i < 26; i++) delete child[i];
        }
    };

    Node* root = new Node();

    Node* walk(const string& s) {
        Node* cur = root;
        for (char c : s) {
            cur = cur->child[c - 'a'];
            if (cur == nullptr) return nullptr;
        }
        return cur;
    }

public:
    ~Trie() { delete root; }

    void insert(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->child[i] == nullptr) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->isEnd = true;
    }

    bool search(const string& word) {
        Node* n = walk(word);
        return n != nullptr && n->isEnd;
    }

    bool startsWith(const string& prefix) {
        return walk(prefix) != nullptr;
    }
};

int main() {
    Trie t;
    t.insert("apple");

    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.startsWith("app") << endl;

    t.insert("app");
    cout << t.search("app") << endl;
    return 0;
}
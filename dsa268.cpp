// Clone a Graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct GNode {
    int val;
    vector<GNode*> nb;
    GNode(int v) : val(v) {}
};

GNode* cloneGraph(GNode* n, unordered_map<GNode*, GNode*>& mp) {
    if (!n) return nullptr;
    if (mp.count(n)) return mp[n];

    GNode* c = new GNode(n->val);
    mp[n] = c;                                   // register before recursing, or cycles never end
    for (GNode* x : n->nb) c->nb.push_back(cloneGraph(x, mp));
    return c;
}

void show(GNode* n, unordered_set<GNode*>& seen) {
    seen.insert(n);
    cout << n->val << ":";
    for (GNode* x : n->nb) cout << " " << x->val;
    cout << endl;
    for (GNode* x : n->nb) {
        if (!seen.count(x)) show(x, seen);
    }
}

int main() {
    GNode* a = new GNode(1);
    GNode* b = new GNode(2);
    GNode* c = new GNode(3);
    GNode* d = new GNode(4);
    a->nb = {b, d};
    b->nb = {a, c};
    c->nb = {b, d};
    d->nb = {a, c};

    unordered_map<GNode*, GNode*> mp;
    GNode* copy = cloneGraph(a, mp);

    unordered_set<GNode*> seen;
    show(copy, seen);
    cout << "Different object: " << (copy != a ? "Yes" : "No") << endl;

    for (auto& p : mp) delete p.second;
    delete a; delete b; delete c; delete d;
    return 0;
}
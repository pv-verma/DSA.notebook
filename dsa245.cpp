// Merge K Sorted Linked Lists (Heap)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

struct Cmp {
    bool operator()(Node* a, Node* b) { return a->data > b->data; }   // min-heap by value
};

Node* mergeK(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (Node* h : lists) {
        if (h) pq.push(h);
    }

    Node dummy(0);
    Node* tail = &dummy;

    while (!pq.empty()) {
        Node* n = pq.top();
        pq.pop();

        tail->next = n;
        tail = n;
        if (n->next) pq.push(n->next);   // the next candidate from the same list
    }
    return dummy.next;
}

Node* build(const vector<int>& v) {
    Node dummy(0);
    Node* t = &dummy;
    for (int x : v) { t->next = new Node(x); t = t->next; }
    return dummy.next;
}

int main() {
    vector<Node*> lists = {build({1, 4, 5}), build({1, 3, 4}), build({2, 6})};

    Node* merged = mergeK(lists);

    for (Node* p = merged; p; p = p->next) cout << p->data << " ";
    cout << endl;

    while (merged) {                     // all nodes are in the merged list now
        Node* n = merged->next;
        delete merged;
        merged = n;
    }
    return 0;
}
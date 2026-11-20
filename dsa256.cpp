// Intersection of Two Linked Lists

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* intersection(Node* a, Node* b) {
    Node* p = a;
    Node* q = b;

    while (p != q) {
        p = p ? p->next : b;     // after finishing list a, continue on list b
        q = q ? q->next : a;     // after finishing list b, continue on list a
    }
    return p;                    // shared node, or nullptr if there is none
}

void freeUntil(Node* h, Node* stop) {
    while (h != stop) {
        Node* n = h->next;
        delete h;
        h = n;
    }
}

int main() {
    Node* shared = new Node(8);
    shared->next = new Node(4);
    shared->next->next = new Node(5);

    Node* a = new Node(4);
    a->next = new Node(1);
    a->next->next = shared;

    Node* b = new Node(5);
    b->next = new Node(6);
    b->next->next = new Node(1);
    b->next->next->next = shared;

    Node* hit = intersection(a, b);
    cout << (hit ? to_string(hit->data) : "none") << endl;

    Node* c = new Node(1);
    c->next = new Node(2);
    Node* d = new Node(3);

    Node* miss = intersection(c, d);
    cout << (miss ? to_string(miss->data) : "none") << endl;

    freeUntil(a, shared);
    freeUntil(b, shared);
    freeUntil(shared, nullptr);
    freeUntil(c, nullptr);
    freeUntil(d, nullptr);
    return 0;
}
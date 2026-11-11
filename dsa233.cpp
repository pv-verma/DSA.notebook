// Add Two Numbers Stored as Linked Lists

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* build(const vector<int>& v) {
    Node dummy(0);
    Node* t = &dummy;
    for (int x : v) {
        t->next = new Node(x);
        t = t->next;
    }
    return dummy.next;
}

Node* addTwo(Node* a, Node* b) {
    Node dummy(0);
    Node* t = &dummy;
    int carry = 0;

    while (a || b || carry) {          // carry alone can still create one more digit
        int s = carry;
        if (a) { s += a->data; a = a->next; }
        if (b) { s += b->data; b = b->next; }

        t->next = new Node(s % 10);
        t = t->next;
        carry = s / 10;
    }
    return dummy.next;
}

void printList(Node* h) {
    for (; h; h = h->next) cout << h->data << " ";
    cout << endl;
}

void freeList(Node* h) {
    while (h) {
        Node* nxt = h->next;
        delete h;
        h = nxt;
    }
}

int main() {
    Node* a = build({2, 4, 3});
    Node* b = build({5, 6, 4});
    Node* s1 = addTwo(a, b);
    printList(s1);

    Node* c = build({9, 9});
    Node* d = build({1});
    Node* s2 = addTwo(c, d);
    printList(s2);

    freeList(a); freeList(b); freeList(s1);
    freeList(c); freeList(d); freeList(s2);
    return 0;
}
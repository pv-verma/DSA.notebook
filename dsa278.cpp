// Copy a List With Random Pointers

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int v) : val(v), next(nullptr), random(nullptr) {}
};

Node* copyList(Node* head) {
    if (!head) return nullptr;

    for (Node* cur = head; cur; cur = cur->next->next) {   // 1: put each copy right after its original
        Node* cp = new Node(cur->val);
        cp->next = cur->next;
        cur->next = cp;
    }

    for (Node* cur = head; cur; cur = cur->next->next) {   // 2: a copy's random is the original's random's copy
        if (cur->random) cur->next->random = cur->random->next;
    }

    Node* copyHead = head->next;                           // 3: split the two lists apart
    for (Node* cur = head; cur; cur = cur->next) {
        Node* cp = cur->next;
        cur->next = cp->next;
        cp->next = cp->next ? cp->next->next : nullptr;
    }
    return copyHead;
}

void show(Node* h) {
    for (; h; h = h->next) {
        cout << h->val << " -> random "
             << (h->random ? to_string(h->random->val) : "null") << endl;
    }
}

void freeList(Node* h) {
    while (h) { Node* n = h->next; delete h; h = n; }
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->next = b; b->next = c;
    a->random = c;
    b->random = a;

    Node* copy = copyList(a);
    show(copy);
    cout << "Separate nodes: " << (copy != a && copy->next != b ? "Yes" : "No") << endl;

    freeList(a);
    freeList(copy);
    return 0;
}
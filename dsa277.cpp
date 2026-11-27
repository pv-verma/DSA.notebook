// Reorder List (inplace)

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* reverseList(Node* h) {
    Node* prev = nullptr;
    while (h) {
        Node* nx = h->next;
        h->next = prev;
        prev = h;
        h = nx;
    }
    return prev;
}

void reorder(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = reverseList(slow->next);   // reverse the back half
    slow->next = nullptr;                     // cut the list in two

    Node* a = head;
    Node* b = second;
    while (b) {                               // weave b nodes between a nodes
        Node* an = a->next;
        Node* bn = b->next;
        a->next = b;
        b->next = an;
        a = an;
        b = bn;
    }
}

Node* build(const vector<int>& v) {
    Node dummy(0);
    Node* t = &dummy;
    for (int x : v) { t->next = new Node(x); t = t->next; }
    return dummy.next;
}

void printList(Node* h) {
    for (; h; h = h->next) cout << h->data << " ";
    cout << endl;
}

void freeList(Node* h) {
    while (h) { Node* n = h->next; delete h; h = n; }
}

int main() {
    Node* a = build({1, 2, 3, 4, 5});
    Node* b = build({1, 2, 3, 4});

    reorder(a); printList(a);
    reorder(b); printList(b);

    freeList(a);
    freeList(b);
    return 0;
}
// Reverse a Linked List in Groups of K

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* reverseK(Node* head, int k) {
    Node* check = head;
    int cnt = 0;
    while (check && cnt < k) {            // is there a full group of k left?
        check = check->next;
        cnt++;
    }
    if (cnt < k) return head;             // fewer than k nodes, leave them as they are

    Node* prev = nullptr;
    Node* cur = head;
    for (int i = 0; i < k; i++) {
        Node* nx = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nx;
    }
    head->next = reverseK(cur, k);        // old head is now the tail of this group
    return prev;
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
    a = reverseK(a, 2);
    printList(a);

    Node* b = build({1, 2, 3, 4, 5});
    b = reverseK(b, 3);
    printList(b);

    freeList(a);
    freeList(b);
    return 0;
}
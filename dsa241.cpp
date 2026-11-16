// Palindrome Linked List

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
        Node* nxt = h->next;
        h->next = prev;
        prev = h;
        h = nxt;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {   // slow stops at the end of the first half
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = reverseList(slow->next);    // reverse the second half in place

    bool ok = true;
    for (Node *p = head, *q = second; q; p = p->next, q = q->next) {
        if (p->data != q->data) { ok = false; break; }
    }

    slow->next = reverseList(second);          // put the list back the way it was
    return ok;
}

Node* build(const vector<int>& v) {
    Node dummy(0);
    Node* t = &dummy;
    for (int x : v) { t->next = new Node(x); t = t->next; }
    return dummy.next;
}

void freeList(Node* h) {
    while (h) { Node* n = h->next; delete h; h = n; }
}

int main() {
    Node* a = build({1, 2, 2, 1});
    Node* b = build({1, 2, 3});

    cout << (isPalindrome(a) ? "Yes" : "No") << endl;
    cout << (isPalindrome(b) ? "Yes" : "No") << endl;

    freeList(a);
    freeList(b);
    return 0;
}
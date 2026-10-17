// Merge Two Sorted Linked Lists (Linked List + Pointers)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeSorted(Node* a, Node* b) {
    Node dummy(0);          // placeholder so the first real node needs no special case
    Node* tail = &dummy;

    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != nullptr) ? a : b;   // attach whichever list has leftovers
    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);

    Node* b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);

    Node* merged = mergeSorted(a, b);
    printList(merged);

    while (merged != nullptr) {
        Node* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}
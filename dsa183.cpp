// Remove the Nth Node from the End (Linked List)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0);
    dummy.next = head;                // handles removing the head itself

    Node* fast = &dummy;
    Node* slow = &dummy;

    for (int i = 0; i < n; i++) fast = fast->next;   // open a gap of n nodes

    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* target = slow->next;        // slow sits just before the node to remove
    slow->next = target->next;
    delete target;

    return dummy.next;
}

int main() {
    Node* head = new Node(1);
    Node* cur = head;
    for (int v = 2; v <= 5; v++) {
        cur->next = new Node(v);
        cur = cur->next;
    }

    head = removeNthFromEnd(head, 2);

    for (Node* p = head; p != nullptr; p = p->next) cout << p->data << " ";
    cout << endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
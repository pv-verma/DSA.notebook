// Detect a Cycle and Find Where It Starts (Linked List)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* cycleStart(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;                  // restart one pointer from the head
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;        // both move one step now
            }
            return slow;                  // they meet at the cycle start
        }
    }
    return nullptr;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    Node* tail = new Node(5);
    head->next->next->next->next = tail;
    tail->next = head->next->next;        // 5 points back to 3

    Node* start = cycleStart(head);
    if (start) cout << "Cycle starts at node with value " << start->data << endl;
    else cout << "No cycle" << endl;

    tail->next = nullptr;                 // break the loop before cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
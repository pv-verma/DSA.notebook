//Implement a Queue Using queue (Simulate Ticket System)

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> ticketQueue;

    ticketQueue.push("Person A");
    ticketQueue.push("Person B");
    ticketQueue.push("Person C");

    cout << "Serving order:\n";
    while (!ticketQueue.empty()) {
        cout << ticketQueue.front() << " is served\n";
        ticketQueue.pop();
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort an array pair by second element


bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;   // descending order by marks
}

int main() {
    vector<pair<int, int>> students = {{1, 85}, {2, 92}, {3, 78}, {4, 92}, {5, 60}};

    sort(students.begin(), students.end(), compare);

    cout << "Sorted (ID, Marks):\n";
    for (auto& p : students)
        cout << p.first << " -> " << p.second << endl;

    return 0;
}
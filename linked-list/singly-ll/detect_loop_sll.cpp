// detect_loop_sll.cpp
// Detect loop in singly linked list using Floyd's Cycle Detection Algorithm

/*
Floyd's Cycle Detection Algorithm (also known as Tortoise and Hare Algorithm):
--------------------------------------------------------------------------
This algorithm is used to detect cycles (loops) in a linked list.
It uses two pointers:
    - Slow pointer (tortoise): moves one step at a time.
    - Fast pointer (hare): moves two steps at a time.
If there is a loop, the fast pointer will eventually meet the slow pointer inside the loop.
If there is no loop, the fast pointer will reach the end (nullptr).

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode Problems to practice:
-----------------------------
1. Linked List Cycle (LeetCode 141): https://leetcode.com/problems/linked-list-cycle/
2. Linked List Cycle II (LeetCode 142): https://leetcode.com/problems/linked-list-cycle-ii/
3. Find the Duplicate Number (LeetCode 287): https://leetcode.com/problems/find-the-duplicate-number/
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creates a loop
    cout << "Loop detected: " << (hasLoop(head) ? "Yes" : "No") << endl;
    // Note: No memory cleanup due to loop
    return 0;
}

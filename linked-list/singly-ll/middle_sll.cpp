// middle_sll.cpp
// Find the middle node of a singly linked list using slow/fast pointers

/*
Algorithm: Slow and Fast Pointer (Tortoise and Hare)
---------------------------------------------------
To find the middle node, use two pointers:
    - Slow pointer moves one step at a time.
    - Fast pointer moves two steps at a time.
When fast pointer reaches the end, slow pointer will be at the middle.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode Problems:
------------------
1. Middle of the Linked List (LeetCode 876): https://leetcode.com/problems/middle-of-the-linked-list/
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    // Slow moves 1 step, fast moves 2 steps
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void traverse(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 7; ++i) {
        Node* newNode = new Node(i);
        newNode->next = head;
        head = newNode;
    }
    cout << "List: "; traverse(head);
    Node* mid = findMiddle(head);
    if (mid) cout << "Middle node: " << mid->data << endl;
    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

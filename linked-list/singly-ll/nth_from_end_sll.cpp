// nth_from_end_sll.cpp
// Find the nth node from the end of a singly linked list

/*
Algorithm: Two Pointer Technique
-------------------------------
Use two pointers. Move the first pointer n steps ahead, then move both pointers until the first reaches the end.
The second pointer will be at the nth node from the end.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode Problems:
------------------
1. Remove Nth Node From End of List (LeetCode 19): https://leetcode.com/problems/remove-nth-node-from-end-of-list/
2. Find the Kth Node From the End (LeetCode 876 variant)
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* nthFromEnd(Node* head, int n) {
    Node* first = head;
    Node* second = head;
    for (int i = 0; i < n; ++i) {
        if (!first) return nullptr;
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    return second;
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
    for (int i = 1; i <= 5; ++i) {
        Node* newNode = new Node(i);
        newNode->next = head;
        head = newNode;
    }
    cout << "List: "; traverse(head);
    int n = 2;
    Node* nth = nthFromEnd(head, n);
    if (nth) cout << n << "th node from end: " << nth->data << endl;
    else cout << "List too short!" << endl;
    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

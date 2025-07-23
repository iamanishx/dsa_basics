// merge_sorted_sll.cpp
// Merge two sorted singly linked lists

/*
Algorithm: Two Pointer Merge
---------------------------
Use two pointers to traverse both lists. At each step, append the smaller node to the result list.
Continue until one list is exhausted, then append the remaining nodes.

Time Complexity: O(n + m)
Space Complexity: O(1) (if merging in-place)

LeetCode Problems:
------------------
1. Merge Two Sorted Lists (LeetCode 21): https://leetcode.com/problems/merge-two-sorted-lists/
2. Merge k Sorted Lists (LeetCode 23): https://leetcode.com/problems/merge-k-sorted-lists/
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeSorted(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void traverse(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);
    cout << "List 1: "; traverse(l1);
    cout << "List 2: "; traverse(l2);
    Node* merged = mergeSorted(l1, l2);
    cout << "Merged: "; traverse(merged);
    // Free memory
    while (merged) {
        Node* temp = merged;
        merged = merged->next;
        delete temp;
    }
    return 0;
}

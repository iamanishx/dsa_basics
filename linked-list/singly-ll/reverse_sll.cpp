// reverse_sll.cpp
// Iterative and recursive reversal of singly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Iterative reversal
void reverseIterative(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Recursive reversal
Node* reverseRecursive(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

// Utility to print list
void traverse(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    // Insert nodes
    for (int i = 1; i <= 5; ++i) {
        Node* newNode = new Node(i);
        newNode->next = head;
        head = newNode;
    }
    cout << "Original: "; traverse(head);
    reverseIterative(head);
    cout << "Reversed (Iterative): "; traverse(head);
    head = reverseRecursive(head);
    cout << "Reversed (Recursive): "; traverse(head);
    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

// palindrome_sll.cpp
// Check if a singly linked list is a palindrome
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Reverse helper
Node* reverse(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    // Find middle
    Node* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse second half
    Node* second = reverse(slow->next);
    Node* first = head;
    Node* copySecond = second;
    bool result = true;
    while (second) {
        if (first->data != second->data) {
            result = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    // Restore list
    slow->next = reverse(copySecond);
    return result;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    cout << "Is palindrome: " << (isPalindrome(head) ? "Yes" : "No") << endl;
    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

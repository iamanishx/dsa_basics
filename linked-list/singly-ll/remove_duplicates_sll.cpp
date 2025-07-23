// remove_duplicates_sll.cpp
// Remove duplicates from a sorted singly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void removeDuplicates(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}

void traverse(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    cout << "Original: "; traverse(head);
    removeDuplicates(head);
    cout << "After removing duplicates: "; traverse(head);
    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

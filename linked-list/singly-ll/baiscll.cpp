
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Traverse and print the linked list
void traverse(Node* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Search for a value in the linked list
bool search(Node* head, int key) {
    while (head) {
        if (head->data == key) return true;
        head = head->next;
    }
    return false;
}

// Get the length of the linked list
int length(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Insert a node at the end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Delete a node by value (first occurrence)
void deleteNode(Node*& head, int key) {
    if (!head) return;
    if (head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

int main() {
    Node* head = nullptr;
    // Example: Insert nodes
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    traverse(head);
    cout << "Length: " << length(head) << endl;

    int key = 30;
    cout << "Searching for " << key << ": ";
    cout << (search(head, key) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20...\n";
    deleteNode(head, 20);
    traverse(head);
    cout << "Length: " << length(head) << endl;

    cout << "Deleting 10...\n";
    deleteNode(head, 10);
    traverse(head);
    cout << "Length: " << length(head) << endl;

    cout << "Deleting 50...\n";
    deleteNode(head, 50);
    traverse(head);
    cout << "Length: " << length(head) << endl;

    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

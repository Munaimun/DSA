// Problem Statement:
// Implement a singly linked list with operations: push_front, push_back, pop_front,
// pop_back, insert at a given position, search a value, and print the list.
// Demonstrate all functions inside main().


// Time & Space Complexity (for each function):
// push_front     → O(1) time, O(1) space
// push_back      → O(1) time (because we track tail), O(1) space
// pop_front      → O(1) time, O(1) space
// pop_back       → O(n) time, O(1) space (needs traversal)
// insert         → O(n) time (depends on position), O(1) space
// search         → O(n) time, O(1) space
// printList      → O(n) time, O(1) space

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {       // constructor → auto called when Node object created
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {        // constructor → initializes empty list
        head = tail = NULL;
    }

    // Insert at front → new head
    void push_front(int val) {
        Node* newNode = new Node(val); // dynamic allocation → lives on heap
        if (head == NULL) {            // if list is empty
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // Insert at end → use tail pointer
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {            // empty list → same as push_front
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // Remove from front → new head
    void pop_front() {
        if (head == NULL) return;      // nothing to delete
        Node* temp = head;
        head = head->next;
        delete temp;                   // free memory → AVIOD LEAKS
    }

    // Remove from end → find previous of tail
    void pop_back() {
        if (head == NULL) return;
        if (head == tail) {            // only 1 element
            delete head;
            head = tail = NULL; // head and tail both are null now
            return;
        }
        Node* temp = head;
        while (temp->next != tail)     // stop before tail
            temp = temp->next;
        delete tail;
        temp->next = NULL;
        tail = temp;
    }

    // Insert before position `pos` (0-indexed)
    void insert(int val, int pos) {
        if (pos < 0) return;
        if (pos == 0) { push_front(val); return; }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) return;  // position too big
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Search and return index of value, else -1
    int search(int val) {
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == val) return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Print entire list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l;

    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    cout << "Initial: ";
    l.printList();

    l.push_back(5);
    cout << "Push back: ";
    l.printList();

    l.pop_front();
    cout << "Pop front: ";
    l.printList();

    l.pop_back();
    cout << "Pop back: ";
    l.printList();

    l.insert(7, 1);
    cout << "Insert at index 1: ";
    l.printList();

    cout << "Search index of value 1: " << l.search(1) << endl;
}

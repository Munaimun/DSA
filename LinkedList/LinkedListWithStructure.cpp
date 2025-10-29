#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List structure to maintain head and tail
struct LinkedList {
    Node* head;
    Node* tail;
};

// Initialize an empty list
void initList(LinkedList &list) {
    list.head = nullptr;
    list.tail = nullptr;
}

// Push at front
void push_front(LinkedList &list, int val) {
    Node* newNode = new Node{val, nullptr};
    if (list.head == nullptr) { // empty list
        list.head = list.tail = newNode;
        return;
    }
    newNode->next = list.head;
    list.head = newNode;
}

// Push at back
void push_back(LinkedList &list, int val) {
    Node* newNode = new Node{val, nullptr};
    if (list.head == nullptr) {
        list.head = list.tail = newNode;
        return;
    }
    list.tail->next = newNode;
    list.tail = newNode;
}

// Pop front
void pop_front(LinkedList &list) {
    if (list.head == nullptr) return;
    Node* temp = list.head;
    list.head = list.head->next;
    if (list.head == nullptr) list.tail = nullptr; // list became empty
    delete temp;
}

// Pop back
void pop_back(LinkedList &list) {
    if (list.head == nullptr) return;
    if (list.head == list.tail) { // only 1 element
        delete list.head;
        list.head = list.tail = nullptr;
        return;
    }
    Node* temp = list.head;
    while (temp->next != list.tail) temp = temp->next;
    delete list.tail;
    temp->next = nullptr;
    list.tail = temp;
}

// Insert at position pos (0-indexed)
void insert(LinkedList &list, int val, int pos) {
    if (pos < 0) return;
    if (pos == 0) { push_front(list, val); return; }

    Node* temp = list.head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == nullptr) return;
        temp = temp->next;
    }
    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;
    if (newNode->next == nullptr) list.tail = newNode; // update tail if inserted at end
}

// Search for value and return index
int search(LinkedList &list, int val) {
    Node* temp = list.head;
    int idx = 0;
    while (temp != nullptr) {
        if (temp->data == val) return idx;
        temp = temp->next;
        idx++;
    }
    return -1;
}

// Print list
void printList(LinkedList &list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to demonstrate
int main() {
    LinkedList l;
    initList(l);

    push_front(l, 1);
    push_front(l, 2);
    push_front(l, 3);
    cout << "Initial: ";
    printList(l);

    push_back(l, 5);
    cout << "Push back: ";
    printList(l);

    pop_front(l);
    cout << "Pop front: ";
    printList(l);

    pop_back(l);
    cout << "Pop back: ";
    printList(l);

    insert(l, 7, 1);
    cout << "Insert at index 1: ";
    printList(l);

    cout << "Search index of value 1: " << search(l, 1) << endl;

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void insertFirst(Node*& head, int x) {
    Node* p = createNode(x);
    p->next = head;
    head = p;
}

void insertLast(Node*& head, int x) {
    Node* p = createNode(x);
    if (head == nullptr) {
        head = p;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = p;
}

void insertValue(Node*& head, int x, int k) {
    if (k < 0) return;
    if (k == 0 || head == nullptr) {
        Node* p = createNode(x);
        p->next = head;
        head = p;
        return;
    }
    Node* cur = head;
    for (int i = 0; i < k - 1 && cur->next != nullptr; i++) {
        cur = cur->next;
    }
    Node* p = createNode(x);
    p->next = cur->next;
    cur->next = p;
}

void deleteFirst(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteLast(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* cur = head;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = nullptr;
}

void deleteValue(Node*& head, int k) {
    if (k < 0 || head == nullptr) return;
    if (k == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* cur = head;
    for (int i = 0; i < k - 1 && cur->next != nullptr; i++) {
        cur = cur->next;
    }
    if (cur->next == nullptr) return;
    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

int getAt(Node* head, int k) {
    if (k < 0) return -1;
    Node* cur = head;
    for (int i = 0; i < k && cur != nullptr; i++) {
        cur = cur->next;
    }
    return (cur != nullptr) ? cur->data : -1;
}

int indexOf(Node* head, int x) {
    int index = 0;
    while (head != nullptr) {
        if (head->data == x) return index;
        head = head->next;
        index++;
    }
    return -1;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printReverseHelper(Node* head) {
    if (head == nullptr) return;
    printReverseHelper(head->next);
    cout << head->data << " ";
}

void printReverse(Node* head) {
    printReverseHelper(head);
    cout << endl;
}

void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


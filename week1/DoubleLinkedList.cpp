#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* createDNode(int x) {
    DNode* p = new DNode;
    p->data = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertFirst(DNode*& head, int x) {
    DNode* p = createDNode(x);
    if (head != nullptr) {
        p->next = head;
        head->prev = p;
    }
    head = p;
}

void insertLast(DNode*& head, int x) {
    DNode* p = createDNode(x);
    if (head == nullptr) {
        head = p;
        return;
    }
    DNode* cur = head;
    while (cur->next != nullptr) cur = cur->next; 
    cur->next = p;
    p->prev = cur;
}

void insertValue(DNode*& head, int x, int k) {
    if (k < 0) return;
    if (k == 0 || head == nullptr) {
        DNode* p = createDNode(x);
        if (head != nullptr) {
            p->next = head;
            head->prev = p;
        }
        head = p;
        return;
    }
    DNode* cur = head;
    for (int i = 0; i < k - 1 && cur->next != nullptr; i++) {
        cur = cur->next;
    }
    DNode* p = createDNode(x);
    p->next = cur->next;
    p->prev = cur;
    if (cur->next != nullptr) cur->next->prev = p;
    cur->next = p;
}

void deleteFirst(DNode*& head) {
    if (head == nullptr) return;
    DNode* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
}

void deleteLast(DNode*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    DNode* cur = head;
    while (cur->next != nullptr) cur = cur->next; 
    cur->prev->next = nullptr;
    delete cur;
}

void deleteValue(DNode*& head, int k) {
    if (head == nullptr || k < 0) return;
    if (k == 0) {
        DNode* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        return;
    }
    DNode* cur = head;
    for (int i = 0; i < k && cur != nullptr; i++) {
        cur = cur->next;
    }
    if (cur == nullptr) return; 

    cur->prev->next = cur->next;
    if (cur->next != nullptr) {
        cur->next->prev = cur->prev;
    }
    delete cur;
}

int getAt(DNode* head, int k) {
    if (k < 0) return -1;
    DNode* cur = head;
    for (int i = 0; i < k && cur != nullptr; i++) {
        cur = cur->next;
    }
    return (cur != nullptr) ? cur->data : -1;
}

int indexOf(DNode* head, int x) {
    int index = 0;
    while (head != nullptr) {
        if (head->data == x) return index;
        head = head->next;
        index++;
    }
    return -1;
}

void printList(DNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printReverse(DNode* head) {
    if (head == nullptr) return;
    DNode* cur = head;
    while (cur->next != nullptr) cur = cur->next; 
    while (cur != nullptr) { 
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
}

void clearList(DNode*& head) {
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
}

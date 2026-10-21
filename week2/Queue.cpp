#include "LinkedList.cpp"
#include "List.cpp"

// cach 1: dung list
void arrEnqueue(int x) { insertLast(x); }                   // O(1)
bool arrDequeue() {                                         // O(n)
    if (n <= 0) return false;
    deleteFirst();
    return true;
}
bool arrFront(int& x) {                                     // O(1)
    if (n <= 0) return false;
    x = getAt(0);
    return true;
}

// cach 2: dung linked list
void llEnqueue(Node*& head, int x) { insertLast(head, x); } // O(n)
bool llDequeue(Node*& head) {                               // O(1)
    if (head == nullptr) return false;
    deleteFirst(head);
    return true;
}
bool llFront(Node* head, int& x) {                          // O(1)
    if (head == nullptr) return false;
    x = head->data;
    return true;
}

int main() {
    int v;

    cout << "Queue (List mang): ";
    n = 0;
    for (int x : {1, 2, 3}) arrEnqueue(x);
    while (arrFront(v)) { cout << v << " "; arrDequeue(); }
    cout << endl;

    cout << "Queue (Linked list): ";
    Node* q = nullptr;
    for (int x : {1, 2, 3}) llEnqueue(q, x);
    while (llFront(q, v)) { cout << v << " "; llDequeue(q); }
    cout << endl;

    clearList(q);
    return 0;
}

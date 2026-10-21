#include "LinkedList.cpp"
#include "List.cpp"

// cach 1: dung list
void arrPush(int x) { insertLast(x); }                      // O(1)
bool arrPop() {                                             // O(1)
    if (n <= 0) return false;
    deleteLast();
    return true;
}
bool arrTop(int& x) {                                       // O(1)
    if (n <= 0) return false;
    x = getAt(n - 1);
    return true;
}

// cach 2: dung linked list
void llPush(Node*& head, int x) { insertFirst(head, x); }   // O(1)
bool llPop(Node*& head) {                                   // O(1)
    if (head == nullptr) return false;
    deleteFirst(head);
    return true;
}
bool llTop(Node* head, int& x) {                            // O(1)
    if (head == nullptr) return false;
    x = head->data;
    return true;
}

int main() {
    int v;

    cout << "Stack (List mang): ";
    n = 0;
    for (int x : {1, 2, 3}) arrPush(x);
    while (arrTop(v)) { cout << v << " "; arrPop(); }
    cout << endl;

    cout << "Stack (Linked list): ";
    Node* s = nullptr;
    for (int x : {1, 2, 3}) llPush(s, x);
    while (llTop(s, v)) { cout << v << " "; llPop(s); }
    cout << endl;

    clearList(s);
    return 0;
}

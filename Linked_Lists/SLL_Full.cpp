#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int search(Node* head, int key) {
    int idx = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next, idx++) {
        if (curr->data == key) {
            return idx;
        }
    }
    return -1;
}

Node* insertAtHead(Node* head, int val) {
    Node* n = new Node(val);
    n->next = head;
    return n;
}

Node* insertAtTail(Node* head, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {
        return n;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = n;
    return head;
}

Node* insertAtPos(Node* head, int pos, int val) {
    if (pos < 0) {
        return head;
    }
    if (pos == 0) {
        return insertAtHead(head, val);
    }

    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return head;
    }

    Node* n = new Node(val);
    n->next = curr->next;
    curr->next = n;
    return head;
}

Node* deleteAtHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteAtTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return head;
}

Node* deleteAtPos(Node* head, int pos) {
    if (head == nullptr || pos < 0) {
        return head;
    }
    if (pos == 0) {
        return deleteAtHead(head);
    }

    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr->next != nullptr; i++) {
        curr = curr->next;
    }
    if (curr->next == nullptr) {
        return head;
    }

    Node* victim = curr->next;
    curr->next = victim->next;
    delete victim;
    return head;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    Node* head = nullptr;

    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 30);
    head = insertAtPos(head, 1, 15);
    printList(head);

    head = deleteAtPos(head, 2);
    printList(head);

    freeList(head);
    return 0;
}

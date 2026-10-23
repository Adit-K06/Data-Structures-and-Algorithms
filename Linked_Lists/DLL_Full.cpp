#include <iostream>
#include <utility>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void printForward(DNode* head) {
    for (DNode* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->data << " <-> ";
    }
    cout << "NULL" << endl;
}

void printBackward(DNode* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }

    DNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    for (; curr != nullptr; curr = curr->prev) {
        cout << curr->data << " <-> ";
    }
    cout << "NULL" << endl;
}

DNode* dInsertHead(DNode* head, int val) {
    DNode* n = new DNode(val);
    n->next = head;

    if (head != nullptr) {
        head->prev = n;
    }
    return n;
}

DNode* dInsertTail(DNode* head, int val) {
    DNode* n = new DNode(val);
    if (head == nullptr) {
        return n;
    }

    DNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = n;
    n->prev = curr;
    return head;
}

DNode* dInsertPos(DNode* head, int pos, int val) {
    if (pos < 0) {
        return head;
    }
    if (pos == 0) {
        return dInsertHead(head, val);
    }

    DNode* curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return head;
    }

    DNode* n = new DNode(val);
    n->next = curr->next;
    n->prev = curr;

    if (curr->next != nullptr) {
        curr->next->prev = n;
    }
    curr->next = n;
    return head;
}

DNode* dDeleteHead(DNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    DNode* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return head;
}

DNode* dDeleteTail(DNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    DNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->prev->next = nullptr;
    delete curr;
    return head;
}

DNode* dDeletePos(DNode* head, int pos) {
    if (head == nullptr || pos < 0) {
        return head;
    }
    if (pos == 0) {
        return dDeleteHead(head);
    }

    DNode* curr = head;
    for (int i = 0; i < pos && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return head;
    }

    curr->prev->next = curr->next;
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    delete curr;
    return head;
}

void dFree(DNode* head) {
    while (head != nullptr) {
        DNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    DNode* head = nullptr;

    head = dInsertHead(head, 20);
    head = dInsertHead(head, 10);
    head = dInsertTail(head, 30);
    head = dInsertPos(head, 2, 25);

    printForward(head);
    printBackward(head);

    head = dDeletePos(head, 2);
    printForward(head);

    dFree(head);
    return 0;
}

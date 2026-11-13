// 1->2->1->3->4->5->4->6->7->8->9->NULL

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

Node* ReverseList(Node* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    Node* temp = head;
    Node* curr = head;
    Node* x = head;
    
    while(curr != nullptr){
        curr = curr->next;
        x->next = curr;
        break;
    }

    while(temp != curr || temp->next != curr){
        swap(temp->data, curr->data);
        temp = temp->next;
        curr = x;
        x->next = curr;
    }

    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* H1 = nullptr;
    Node* H2 = nullptr;

    H1 = insertAtHead(H1, 1);
    H1 = insertAtTail(H1, 2);
    H1 = insertAtTail(H1, 1);
    H1 = insertAtTail(H1, 3);
    H1 = insertAtTail(H1, 4);
    H1 = insertAtTail(H1, 5);
    H1 = insertAtTail(H1, 4);
    H1 = insertAtTail(H1, 6);
    H1 = insertAtTail(H1, 7);
    H1 = insertAtTail(H1, 8);
    H1 = insertAtTail(H1, 9);
    printList(H1);

    Node* Rev = ReverseList(H1);
    printList(Rev);
}
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

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

Node* Remove_Nth_node_from_end(Node* head, int n){
    Node* curr = head;

    for(int i=0; i<n; i++){
        curr = curr->next;
    }

    Node* temp = new Node(0);

    temp->next = head;

    while(curr->next != nullptr){
        curr = curr->next;
        temp = temp->next;
    }

    cout << "Deleting: " << temp->next->data << endl;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    // temp = temp->next;

    return head;
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

    int n;
    cout << "Enter N: " << endl;
    cin >> n;
    H1 = Remove_Nth_node_from_end(H1, n);
    printList(H1);
}
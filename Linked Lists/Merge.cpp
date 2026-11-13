// 1->2->3->7->8->9
//          i
//       t
// 3->4->5->6
//    j

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

Node* merge(Node* H1, Node* H2){
    Node* curr1 = H1;
    Node* curr2 = H2;
    Node* temp = H1;

    while(curr1 != nullptr && curr2 != nullptr){
        if(curr1->data <= curr2->data){
            temp = curr1;
            curr1 = curr1->next;
            temp->next = curr1;
        }
        else{
            Node* n = new Node(curr2->data);
            temp->next = n;
            n->next = curr1;
            curr2 = curr2->next;
            temp = n;
        }
    }

    while(curr2 != nullptr){
        Node* n = new Node(curr2->data);
        temp->next = n;
        temp = n;
        curr2 = curr2->next;
    }

    return H1;
}

int main() {
    Node* H1 = nullptr;
    Node* H2 = nullptr;

    H1 = insertAtHead(H1, 1);
    H1 = insertAtTail(H1, 2);
    H1 = insertAtTail(H1, 7);
    H1 = insertAtTail(H1, 8);
    H1 = insertAtTail(H1, 9);
    printList(H1);

    H2 = insertAtHead(H2, 3);
    H2 = insertAtTail(H2, 4);
    H2 = insertAtTail(H2, 5);
    H2 = insertAtTail(H2, 6);
    printList(H2);

    H1 = merge(H1, H2);
    printList(H1);
}
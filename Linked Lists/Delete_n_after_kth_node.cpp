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

Node* circular(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = head; // Make the last node point to the head
    return head;
    
}

Node* remove_N_after_K(Node* head, int k, int n){
    if(head == nullptr || head->next == nullptr || k < 0 || n < 0){
        return head;
    }

    Node* curr = head;
    Node* temp = head;
    int count = 0;

    while(count <= k && curr != nullptr){
        temp = curr;
        curr = curr->next;
        count++;
    }


    while(count > k && curr != nullptr){
        if(curr->data == n){
            temp->next = curr->next;
            delete curr;
            curr = temp->next;
        }
        else{
            temp = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printCircularList(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* curr = head;
    while(curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
        if (curr == head) {
            break;  
        }
    }
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

    H1 = circular(H1);
    printCircularList(H1);

    H1 = remove_N_after_K(H1, 3, 4);
    printCircularList(H1);
}
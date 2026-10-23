#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr){}
};

void printList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}


int main(){
    Node* a = new Node(10);
    Node* b = new Node(15);
    Node* c = new Node(20);

    a->next = b;
    b->next = c;
    Node* head = a;

    printList(head);
}
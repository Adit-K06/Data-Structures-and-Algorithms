# Linked Lists
## Why linked lists when compared to any other Data structure: 
When compared to an array, an array always stores all of its elements in one single block of memory whereas a linked list stores all its elements seperately in its own small boxes - called nodes. These nodes can be anywhere in the memory. Each node holds the address of the next node. 

Examples : 
1) Music playlist - previous and the next songs (Doubly linked list)
2) Browser - back and forward buttons (Doubly linked list)

## Pointers, struct, new and delete operators: 
### Memory and addresses: 
We can understand with an analogy: Assume a computer momery is like a big street with houses. Each house has a number (address) and any house may have something inside it, we can understand it as a variable. 

A **pointer** can be understood as a sticky note with a house number. It tells us the **direction** to that house. A **nullptr** is the one sticky note which says "no house".

```cpp
int x = 5; 
int *p = &x; // p here is a pointer variable that holds the value of address of the variable x
cout << *p; // *p = go to house x and check what's inside and print that. Prints = 5
*p = 9; // Change whatever is there in that house to 9

int *q = nullptr;
```

## Struct: 
A struct basically bundles more than one variables under one name. For linked lists, we will be working with a **node** struct which will contain the the value of the current node and the address to the next node.

```cpp
struct Node {
    int data; // The value we store
    Node* next; // Address of the next node. 

    Node(int val): data(val), next(nullptr) {}; // Constructor
}
```
*Why are we using a constructor here?* A constructor is basically a special function that runs automatically whenever a new Node object is created.

## The arrow operator: 
The arrow (->) operator basically an operator which helps in retriving the inner data of the a struct

```cpp
Node* n = new Node(10);
cout << n->data;
// this is same as 
cout << (n*).data; // Looks ugly man
```

## Memory of a linked list : 
A linked list elements is stored in a **heap** memory instead of a **stack**. We can understand it in this way - A **Stack** can be understood as a desk, where after a certain function the desk is automatically cleared whereas a **heap** is like a small storage unit taken for rent using new. It stays until we give it back using delete.

# Singly Linked List (SLL) : 
Elements of a SLL: 
- Node : One single structure with data and the pointer to the next node. 
- Head : Pointer to the first node. We cannot afford to lose the head. 
- Tail : The last node. The next pointer of this is a nullptr.
- Empty list : Head == nullptr.

## Building a list by hand: 
```cpp
void manualDemo(){
    Node* a = new Node(10);
    Node* b = new Node(15);
    Node* c = new Node(20);

    a->next = b;
    b->next = c;
    Node* head = a;

    printList(head);
}
```
### Looping thru the list: 
While looping thru the list we cannot move the actual head, instead we take a helper variable **curr** and move that. We move **curr** starting from head, until it doesnt reach the nullptr and then keep printing out the values.

```cpp
void printList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}
```

### Searching an element in the list: 
This function return a 0-index based of the first match, or -1 if there is no match.

```cpp
void search(Node* head, int val){
    int i = 0;
    for(Node* curr = head, curr != nullptr; cur=curr->next, i++){
        if(curr->data == val) return i;
    }
    return -1;
}
```

### Inserting at the head
Just 3 steps: 
- Make a new node with the value
- Then set the next pointer of new node to head
- Return the new node.
```cpp
Node* insertAtHead(Node* head, int val){
    Node* n = new Node(10);
    n->next = head;
    return n;   
}
```

### Inserting at the tail(end)
Just 3 steps:
- Make a new node. 
- Check if it is an empty List. If yes just return n.
- If not, move to the tail (using **curr->next != nullptr**) and then assign **curr->next = n**
- At last return n.
```cpp
Node* insertAtTail(Node* head, int val){
    Node* n = new Node(10);
    if(head == nullptr) return n;
    Node* curr = head;
    while(curr->next != nullptr){
        curr=curr->next;
    }
    curr->next = n;
    return n
}
```

### Insert at Nth position: 
Steps:
- Check if pos < 0. If yes, return head.
- If pos == 0, insert the node at the head using insertAtHead(head, val) and return it.
- Otherwise, move to the node at position pos - 1, check if curr == nullptr, and if not, make a new node, link it using n->next = curr->next and curr->next = n, then return head.

```cpp
Node* insertAtPos(Node* head, int pos, int val){
    if (pos < 0) return head;
    if (pos == 0) return insertAtHead(head, val);

    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++){
        curr = curr->next;
    } 
    if (curr == nullptr) return head;
    Node* n = new Node(val);
    n->next = curr->next; 
    curr->next = n; 

    return head;
}

```

## Deleting in a Singly linked list: 
### Delete at head:
Steps: 
- Check if the list is empty (head == nullptr). If yes, return nullptr.
- Store the head in a temporary pointer (temp) and move head to the next node (head = head->next).
- Delete temp and return head.

``` cpp
Node* deleteAtHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next; 
    delete temp; 
    return head;
}

```

### Delete at tail: 
Steps: 
- Check if the list is empty (head == nullptr). If yes, return nullptr.
- If there is only one node (head->next == nullptr), delete it and return nullptr.
- Otherwise, move to the second-last node using curr->next->next != nullptr, delete the last node, assign curr->next = nullptr, and return head.

```cpp
Node* deleteAtTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) { 
        delete head;
        return nullptr;
    }
    Node* curr = head;
    while (curr->next->next != nullptr){
        curr = curr->next;
    }
    delete curr->next; 
    curr->next = nullptr; 
    return head;
}
```


# Doubly Linked List (DLL)

In a SLL, we can only move forward, but in a DLL, we can move both forward and backward.

### Why DLL?
- We can traverse in both directions.
- Deletion is easier when we already have the pointer to the node.
- We need extra memory to store the `prev` pointer.

### Structure of a DLL Node

```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
```

### Traversal in DLL

**Forward Traversal**

1. Start from the head.
2. Print the data of the current node.
3. Move to the next node using `next`.
4. Continue until `curr == nullptr`.

```cpp
void printForward(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
```

**Backward Traversal**

1. First, reach the last node.
2. Start traversing backward using `prev`.
3. Continue until `curr == nullptr`.

```cpp
void printBackward(Node* head) {
    if (head == nullptr) return;

    Node* curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
}
```

### Insert at Head

1. Create a new node.
2. Set its `next` to the current head.
3. If the list is not empty, set the current head's `prev` to the new node.
4. Make the new node the head.

```cpp
Node* insertAtHead(Node* head, int val) {
    Node* n = new Node(val);

    n->next = head;

    if (head != nullptr) {
        head->prev = n;
    }

    head = n;
    return head;
}
```

### Insert at Tail

1. Create a new node.
2. If the list is empty, return the new node as head.
3. Traverse to the last node.
4. Set the last node's `next` to the new node.
5. Set the new node's `prev` to the last node.

```cpp
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
    n->prev = curr;

    return head;
}
```

### Insert at Nth Position (1-based indexing)

1. If position is `1`, insert at head.
2. Traverse to the node just before the required position.
3. Connect the new node to the next node.
4. Update both `next` and `prev` pointers.

```cpp
Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos <= 0) return head;

    if (pos == 1) {
        return insertAtHead(head, val);
    }

    Node* curr = head;

    for (int i = 1; curr != nullptr && i < pos - 1; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) return head;

    Node* n = new Node(val);

    n->next = curr->next;
    n->prev = curr;

    if (curr->next != nullptr) {
        curr->next->prev = n;
    }

    curr->next = n;

    return head;
}
```

### Delete at Head

1. If the list is empty, return `nullptr`.
2. Store the current head in a temporary pointer.
3. Move the head to the next node.
4. Set the new head's `prev` to `nullptr`.
5. Delete the old head.

```cpp
Node* deleteAtHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return head;
}
```

### Delete at Tail (Last Node)

1. If the list is empty, return `nullptr`.
2. If there is only one node, delete it and return `nullptr`.
3. Traverse to the last node.
4. Set the previous node's `next` to `nullptr`.
5. Delete the last node.

```cpp
Node* deleteAtTail(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->prev->next = nullptr;
    delete curr;

    return head;
}
```

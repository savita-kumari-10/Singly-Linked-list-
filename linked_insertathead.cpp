#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Insert an element at the beginning of the doubly linked list
void insert_at_head(Node*& head, Node*& tail, int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insert_at_tail(Node*& tail, int d) {
    cout << "Insert at tail" << endl;
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


// Insert an element at the ith position in the doubly linked list
void insert_at_position(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insert_at_head(head, tail, d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Remove an element from the beginning of the doubly linked list
void remove_from_head(Node*& head, Node*& tail) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // List becomes empty
    }
    delete temp;
}

// Delete from the tail of the singly linked list
void delete_at_tail(Node*& head, Node*& tail) {
    cout << "Delete at tail" << endl;
    if (tail == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head == tail) { // Only one element
        delete tail;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
}

// Remove an element from the ith position in the doubly linked list
void remove_at_position(Node*& head, Node*& tail, int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (position == 1) {
        remove_from_head(head, tail);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Update tail if last node is deleted
    }

    delete temp;
}

// Reverse the linked list
void reverse_linked_list(Node*& head) {
    cout << "Reverse the linked list" << endl;
    if (head == NULL || head->next == NULL) {
        return; // No need to reverse if empty or single node
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        Node* next = current->next;
        current->next = prev;
        current->prev = next; // Update the prev pointer
        prev = current;
        current = next;
    }

    head = prev; // Update head to point to the new first node
}

// Search for an element in the doubly linked list
Node* search(Node* head, int d) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == d) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Display the doubly linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insert_at_head(head, tail, 10);
    display(head);

    insert_at_head(head, tail, 20);
    display(head);

    insert_at_tail(tail, 10);
    if (head == NULL) head = tail;
    display(head);

    insert_at_tail(tail, 20);
    display(head);

    insert_at_tail(tail, 30);
    display(head);

    insert_at_position(head, tail, 2, 15);
    display(head);

    remove_from_head(head, tail);
    display(head);

    delete_at_tail(head, tail);
    display(head);

    remove_at_position(head, tail, 2);
    display(head);
    
    reverse_linked_list(head);
    display(head);

    Node* found = search(head, 15);
    if (found) {
        cout << "Element found: " << found->data << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
       
          
          

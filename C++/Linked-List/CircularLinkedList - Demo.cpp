/*

Circular Linked List has the last node pointing to the head of the list, thus forming a circle.

Example : Head --> Node1 --> Node2 --> Node3 --> ... --> LastNode
            ↑                                               ↓
            |_______________________________________________|

Functionalities :
1. Insert Node : Insert a new node in one of the following positions 👇
    ▶ Begenning
    ▶ After Nth Node
    ▶ End
2. Search Node : Perform a linear search on the list to find Nth Node.
3. Delete Nth Node : Delete Nth Node from the list.

*/

#include <iostream> // input output services
using namespace std;

// Node Class which will be a blueprint for all the nodes in the list.
class Node {
public:
    int data; // value held by node
    Node *next; // pointer to the next node
    Node(int data) { // parameterized constructor
        this->data = data; // node value set to data inserted by user
        this->next = NULL; // node points to NULL by default
    }
};

// Linked List Class with head of list and all member functions
class LinkedList {
    Node *head; // pointer to head of list

public:
    LinkedList() { head = NULL; } // unparameterized constructor with head pointing to NULL
    void insertFront(int); // Insert node at front of list
    void insertAfterPos(int, int); // Insert node after nth node in list
    void insertEnd(int); // Insert node at end of list
    void deleteNode(int); // Delete nth node from list
    void searchNode(int); // Search a node by value
    void printList(); // Print whole list
} list;

// Function for choice of insertion position
void insertionChoice() {
    int c, ele, pos;
    cout << "\nChoose Insertion Position :\n1. Front\n2. After Nth Node\n3. End\n\tMAKE YOUR CHOICE : ";
    cin >> c;
    
    switch(c) {
    case 1: // Front
        cout << "Enter element to be inserted : ";
        cin >> ele; // get element to be inserted
        list->insertFront(ele); // function call
        cout << "\n\tElement inserted successfully at front";
        break;

    case 2: // After Nth Node
        cout << "Enter nth position : ";
        cin >> pos; // get insertion position
        cout << "Enter element to be inserted : ";
        cin >> ele; // get element to be inserted
        list->insertAfterPos(pos, ele); // function call
        break;

    case 3: // End
        cout << "Enter element to be inserted : ";
        cin >> ele; // get element to be inserted
        list->insertEnd(ele); // function call

    default:
        cout << "\n\t*** INVALID INPUT ***";
        break;
    }
}

// Insert at front of list
void LinkedList::insertFront(int ele) {
    Node *newNode = new Node(ele); // newNode decleration by passing value to constructor
    if(!head) { // if empty list (head pointing to NULL)
        head = newNode; // head pointer points newNode
        newNode->next = head; // newNode points back to head node
        return;
    }
    Node *p = head; // pointer to traverse till end of list
    newNode->next = head->next;
    while(p) p = p->next; // traverse to end of list
    p->next = newNode; // point last node back to newNode (new head)
    cout << "\n\tElement inserted successfully at front";
}

// Insert after nth node
void LinkedList::insertAfterPos(int pos, int ele) {
    Node *newNode = new Node(ele); // newNode decleration by passing value to constructor
    if(!head) { // if empty list (head pointing to NULL))
        head = newNode; // head pointer points newNode
        newNode->next = head; // newNode points back to head node
        return;
    }

    Node *p = head; // traversal pointer
    int len = 0; // list length counter
    while(p) { ++len; p = p->next; } // find list length

    // if postion more than list length
    if(len < pos) { cout << "Index Out Of Range" << endl; return; }

    p = head; // point to head node for traversal
    while(pos-- > 1) p = p->next; // traverse to nth node / position
    newNode->next = p->next; // point newNode's next to nth node's next
    p->next = newNode; // point nth node's next to newNode
    if(!newNode->next) newNode->next = head; // point newNode back to head node if insertion done after last node
    cout << "\n\tElement inserted successfully";
}

// Insert at end of list
void LinkedList::insertEnd(int ele) {
    Node *newNode = new Node(ele); // newNode decleration by passing value to constructor
    if(!head) { // if empty list (head pointing to NULL)
        head = newNode; // make head point back to newNode
        newNode->next = head; // make newNode point back to head
        return;
    }
    Node *p = head; // pointer to traverse till end of list
    while(p->next) p = p->next; // traverse to end of list
    p->next = newNode; // point last node to newNode
    newNode->next = head; // point newNode back to head node of list
    cout << "\n\tElement inserted successfully at end";
}

// Deletion method
void LinkedList::deleteNode(int pos) {
    Node *p1 = head, *p2 = NULL; // traversal pointers
    int len = 0; // list length counter
    if(!head) { cout << "EMPTY LIST" << endl; return; }

    while(p1) { ++len; p1 = p1->next; } // find list length

    // check if postion more than list length
    if(len < pos) { cout << "Index Out Of Range" << endl; return; }
    
    p1 = head; // point back to head node
    // if head node to be deleted
    if(pos == 1) {
        head = head->next; // point head pointer to head node's next node
        delete p1; // delete head node (pointed by p1)
        cout << "\n\t!!! ELEMENT DELETED !!!";
        return;
    }
    // delete nth node
    while(pos-- > 1) { p2 = p1; p1 = p1->next; } // traverse to nth node / position
    p2->next = p1->next; // point nth node to next node's next
    delete p1; // delete nth node
    if(p2->next == NULL) p2->next = head; // point back to head if last node deleted
    cout << "\n\t!!! ELEMENT DELETED !!!";
}

// Search method
void LinkedList::searchNode(int key) {
    Node *p = head; // traversal pointer
    while(p) {
        if(p->data == key) { // current node's data equals key
            cout << "\n!!! ELEMENT FOUND !!!";
            return;
        }
        p = p->next; // point to next node
    }
    cout << "\n*** ELEMENT NOT FOUND ***";
}

// Print method
void LinkedList::printList() {
    Node *p = head; // traversal pointer
    if(!head) { cout << "Empty List" << endl; return; } // empty list
    while(p) { cout << p->data << " "; p = p->next; } // print node data and point to next node
}

// Main function
int main() {
    // LinkedList list; // object decleration
    int ele, c; // choice varaible
    char ch = 'y';

    cout << "======= CIRCULAR LINKED LIST =======";

    // Input code
    while(ch == 'y') {
        // main menu
        cout << "\nChoose an operation :\n1. Insertion\n2. Deletion\n3. Search\n4. Print";
        cout << "\n\tMAKE YOUR CHOICE : ";
        cin >> c; // input menu choice
        switch(c) {
        case 1: // Insertion
            insertionChoice(); // function call for insertion operations
            break;

        case 2: // Deletion
            cout << "\nDELETION\nEnter the position for deletion : ";
            cin >> ele; // input element to be deleted
            list.deleteNode(ele); // function call for deletion
            break;

        case 3: // Searching
            cout << "\nSEARCHING\nEnter the element to be searched : ";
            cin >> ele; // input element to be searched
            list.searchNode(ele); // function call for search
            break;

        case 4: // Print
            cout << "\nList Elements : ";
            list.printList(); // function call for printing list
            break;

        default:
            cout << "\n\t*** INVALID INPUT ***";
            break;
        }
        cout << "\n\tTry Again ? (y/n) : ";
        cin >> ch; // input repeat choice
    }
    return 0;
}
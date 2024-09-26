#include <iostream>
#include "../include/DoublyCircularLinkedList.h" // Include the header file

using namespace std;

int main() {
    // Create an instance of DoublyCircularLinkedList for integers
    DoublyCircularLinkedList<int> dcl;

    // Insert nodes at the beginning and end
    dcl.InsertFirst(10);
    dcl.InsertLast(20);
    dcl.InsertLast(30);
    dcl.InsertFirst(5);

    // Display the list in forward direction
    cout << "Doubly Circular Linked List (Forward): ";
    dcl.DisplayForward();

    // Display the list in backward direction
    cout << "Doubly Circular Linked List (Backward): ";
    dcl.DisplayBackward();

    // Insert nodes at specific positions
    dcl.InsertAtPos(15, 3); // Insert 15 at position 3
    cout << "After inserting 15 at position 3:\n";
    dcl.DisplayForward();

    // Delete nodes
    dcl.DeleteFirst();
    cout << "After deleting the first node:\n";
    dcl.DisplayForward();

    dcl.DeleteLast();
    cout << "After deleting the last node:\n";
    dcl.DisplayForward();

    dcl.DeleteAtPos(2); // Delete node at position 2
    cout << "After deleting node at position 2:\n";
    dcl.DisplayForward();

    // Display the count of nodes
    cout << "Total nodes in the list: " << dcl.Count() << endl;

    return 0;
}

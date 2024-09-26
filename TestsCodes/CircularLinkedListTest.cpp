#include <iostream>
#include "../include/CircularLinearLinkedList.h" // Include the header file for the singly circular linked list

using namespace std;

int main()
{
    SinglyCircularLinkedList<int> list; // Create an instance of the singly circular linked list

    // Hardcoded values to insert into the list
    list.InsertFirst(10);     // Insert 10 at the beginning
    list.InsertLast(20);      // Insert 20 at the end
    list.InsertLast(30);      // Insert 30 at the end
    list.InsertAtPos(15, 2);  // Insert 15 at position 2

    cout << "List after insertions:\n";
    list.Display();           // Display the current list

    cout << "Count of nodes: " << list.Count() << endl; // Count nodes

    list.DeleteFirst();       // Delete the first node
    cout << "List after deleting the first node:\n";
    list.Display();           // Display the current list

    list.DeleteLast();        // Delete the last node
    cout << "List after deleting the last node:\n";
    list.Display();           // Display the current list

    list.DeleteAtPos(2);      // Delete node at position 2
    cout << "List after deleting node at position 2:\n";
    list.Display();           // Display the current list

    return 0;
}

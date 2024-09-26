/////////////////////////////////////////////////////////////
// Doubly Circular Linked List Implementation
// 
// Description: 
// This class represents a doubly circular linked list using templates.
// It provides methods to insert, delete, and display nodes.
//
// Author: Om Karadkar
// Date: 10/04/2024
// Version: 1.0
/////////////////////////////////////////////////////////////

using namespace std;

template <class T>
class DoublyCircularLinkedList
{
    private:
        struct Node
        {
            T data;                    // Data part of the node
            struct Node *next; // Pointer to the next node
            struct Node *prev; // Pointer to the previous node
        };
        struct Node *Head; // Pointer to the first node (head)
        int NodeCount;                  // Count of the number of nodes

    public:
        // Constructor to initialize list
        DoublyCircularLinkedList();

        // Display all nodes in forward direction
        void DisplayForward();

        // Display all nodes in backward direction
        void DisplayBackward();

        // Return the number of nodes in the list
        int Count();

        // Insert node at the beginning
        void InsertFirst(T value);

        // Insert node at the end
        void InsertLast(T value);

        // Insert node at a specific position
        void InsertAtPos(T value, int position);

        // Delete the first node
        void DeleteFirst();

        // Delete the last node
        void DeleteLast();

        // Delete node at a specific position
        void DeleteAtPos(int position);
};

template <class T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList()
{
    Head = NULL; // Initialize head pointer to NULL
    NodeCount = 0; // Initialize node count to 0
}

template <class T>
void DoublyCircularLinkedList<T>::DisplayForward()
{
    if (Head == NULL) 
    {
        cout << "Doubly Circular Linked List is empty\n";
        return;
    }

    struct Node *temp = Head; // Temp pointer to traverse the list

    do
    {
        cout << "| " << temp->data << " | <-> "; // Display node data
        temp = temp->next; // Move to the next node
    } while (temp != Head);
    
    cout << "...\n"; // Indicate circular nature
}

template <class T>
void DoublyCircularLinkedList<T>::DisplayBackward()
{
    if (Head == NULL) 
    {
        cout << "Doubly Circular Linked List is empty\n";
        return;
    }

    struct Node *temp = Head; // Temp pointer to traverse to the last node

    // Traverse to the last node
    while (temp->next != Head) 
    {
        temp = temp->next;
    }

    // Display nodes in reverse order
    do
    {
        cout << "| " << temp->data << " | <-> "; // Display node data
        temp = temp->prev; // Move to the previous node
    } while (temp->next != Head);
    
    cout << "...\n"; // Indicate circular nature
}

template <class T>
int DoublyCircularLinkedList<T>::Count()
{
    return NodeCount; // Return the total count of nodes
}

template <class T>
void DoublyCircularLinkedList<T>::InsertFirst(T value)
{
    struct Node *newNode = new Node;

    newNode->data = value;     // Assign the data value
    newNode->next = NULL;      // Initially, next will be set later
    newNode->prev = NULL;      // Initially, prev will be set later

    if (Head == NULL)           // If list is empty
    {         
        Head = newNode;
        newNode->next = Head;   // Point to itself
        newNode->prev = Head;    // Point to itself
    } else 
    {
        struct Node *tail = Head->prev; // Get the last node

        newNode->next = Head;   // New node points to head
        newNode->prev = tail;   // New node's prev points to tail
        tail->next = newNode;    // Tail's next points to new node
        Head->prev = newNode;    // Head's prev points to new node
        Head = newNode;          // Update head to new node
    }
    NodeCount++;               // Increment node count
}

template <class T>
void DoublyCircularLinkedList<T>::InsertLast(T value)
{
    struct Node *newNode = new Node;

    newNode->data = value;     // Assign the data value
    newNode->next = NULL;      // Initially, next will be set later
    newNode->prev = NULL;      // Initially, prev will be set later

    if (Head == NULL)           // If list is empty
    {         
        Head = newNode;
        newNode->next = Head;   // Point to itself
        newNode->prev = Head;    // Point to itself
    } else 
    {
        struct Node *tail = Head->prev; // Get the last node

        newNode->next = Head;   // New node points to head
        newNode->prev = tail;   // New node's prev points to tail
        tail->next = newNode;    // Tail's next points to new node
        Head->prev = newNode;    // Head's prev points to new node
    }
    NodeCount++;               // Increment node count
}

template <class T>
void DoublyCircularLinkedList<T>::InsertAtPos(T value, int position)
{
    if (position < 1 || position > NodeCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1)
    {
        InsertFirst(value);  // If inserting at the first position
    }
    else if (position == NodeCount + 1)
    {
        InsertLast(value);   // If inserting at the last position
    }
    else
    {
        struct Node *temp = Head;

        struct Node *newNode = new Node;
        newNode->data = value;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next; // Traverse to the position before insertion
        }

        newNode->next = temp->next; // Insert the new node at the desired position
        newNode->prev = temp;        // Link the new node with the previous node
        temp->next->prev = newNode;  // Link the next node's prev to the new node
        temp->next = newNode;        // Link the previous node's next to the new node

        NodeCount++;  // Increment node count
    }
}

template <class T>
void DoublyCircularLinkedList<T>::DeleteFirst()
{
    if (Head == NULL)           // If list is empty
    {
        cout << "Doubly Circular Linked List is empty\n";
        return;
    }

    struct Node *temp = Head; // Temp pointer to hold the head

    if (Head->next == Head)         // Only one node in the list
    {  
        delete temp;            // Delete the only node
        Head = NULL;            // Update head to NULL
    }
    else 
    {
        struct Node *tail = Head->prev; // Get the last node
        Head = Head->next;      // Update head to the next node
        tail->next = Head;       // Update the last node's next pointer
        Head->prev = tail;       // Update the new head's prev pointer
        delete temp;             // Delete the old head
    }
    NodeCount--;               // Decrement node count
}

template <class T>
void DoublyCircularLinkedList<T>::DeleteLast()
{
    if (Head == NULL)           // If list is empty
    {
        cout << "Doubly Circular Linked List is empty\n";
        return;
    }

    if (Head->next == Head)     // Only one node in the list
    {
        delete Head;
        Head = NULL;
    }
    else                       // Traverse to the last node
    {
        struct Node *tail = Head->prev;

        tail->prev->next = Head; // Update the second last node's next to head
        Head->prev = tail->prev;  // Update head's prev pointer
        delete tail;               // Delete the last node
    }
    NodeCount--;               // Decrement node count
}

template <class T>
void DoublyCircularLinkedList<T>::DeleteAtPos(int position)
{
    if (position < 1 || position > NodeCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1)
    {
        DeleteFirst();        // If deleting the first node
    }
    else if (position == NodeCount)
    {
        DeleteLast();         // If deleting the last node
    }
    else
    {
        struct Node *temp = Head;

        for (int i = 1; i < position; i++)
        {
            temp = temp->next; // Traverse to the node to delete
        }

        struct Node *targetNode = temp; // Node to delete

        targetNode->prev->next = targetNode->next; // Bypass the node to delete
        targetNode->next->prev = targetNode->prev; // Bypass the node to delete
        delete targetNode; // Delete the target node
        NodeCount--;        // Decrement node count
    }
}

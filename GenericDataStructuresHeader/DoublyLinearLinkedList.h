/////////////////////////////////////////////////////////////
// Doubly Linear Linked List Implementation
// 
// Description: 
// This class represents a doubly linear linked list using templates.
// It provides methods to insert, delete, and display nodes.
//
// Author: Om Karadkar
// Date: 10/04/2024
// Version: 1.0
/////////////////////////////////////////////////////////////

template <class T>
class DoublyLinkedList
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
        DoublyLinkedList();

        // Display all nodes from head to tail
        void DisplayForward();

        // Display all nodes from tail to head
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
DoublyLinkedList<T>::DoublyLinkedList()
{
    Head = NULL; // Initialize head pointer to NULL
    NodeCount = 0; // Initialize node count to 0
}

template <class T>
void DoublyLinkedList<T>::DisplayForward()
{
    struct Node *temp = Head; // Temp pointer to traverse the list

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <-> "; // Display node data
        temp = temp->next; // Move to the next node
    }
    cout << "NULL\n"; // Indicate end of the list
}

template <class T>
void DoublyLinkedList<T>::DisplayBackward()
{
    if (Head == NULL) 
    {
        cout << "Doubly Linked List is empty\n";
        return;
    }

    // Traverse to the last node
    struct Node *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Display nodes in reverse order
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <-> "; // Display node data
        temp = temp->prev; // Move to the previous node
    }
    cout << "NULL\n"; // Indicate end of the list
}

template <class T>
int DoublyLinkedList<T>::Count()
{
    return NodeCount; // Return the total count of nodes
}

template <class T>
void DoublyLinkedList<T>::InsertFirst(T value)
{
    struct Node *newNode = new Node;

    newNode->data = value;     // Assign the data value
    newNode->next = Head;      // Point new node's next to current head
    newNode->prev = NULL;      // New node is the first node, so prev is NULL

    if (Head != NULL) 
    {
        Head->prev = newNode;  // Update the previous head's prev pointer
    }
    
    Head = newNode;            // Update head to new node
    NodeCount++;               // Increment node count
}

template <class T>
void DoublyLinkedList<T>::InsertLast(T value)
{
    struct Node *newNode = new Node;

    newNode->data = value;     // Assign the data value
    newNode->next = NULL;      // Last node's next is always NULL
    newNode->prev = NULL;      // Not used but set for clarity

    if (Head == NULL)           // If list is empty, make the new node the head
    {         
        Head = newNode;
    } else 
    {
        struct Node *temp = Head;

        while (temp->next != NULL) 
        {
            temp = temp->next; // Traverse to the last node
        }

        temp->next = newNode;  // Set last node's next to the new node
        newNode->prev = temp;   // Set new node's prev to the last node
    }
    NodeCount++;               // Increment node count
}

template <class T>
void DoublyLinkedList<T>::InsertAtPos(T value, int position)
{
    if(position < 1 || position > NodeCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(position == 1)
    {
        InsertFirst(value);  // If inserting at the first position
    }
    else if(position == NodeCount + 1)
    {
        InsertLast(value);   // If inserting at the last position
    }
    else
    {
        struct Node *temp = Head;

        struct Node *newNode = new Node;
        newNode->data = value;

        for(int i = 1; i < position - 1; i++)
        {
            temp = temp->next; // Traverse to the position before insertion
        }

        newNode->next = temp->next; // Insert the new node at the desired position
        newNode->prev = temp;        // Link the new node with the previous node
        if (temp->next != NULL) {
            temp->next->prev = newNode; // Link the next node's prev to the new node
        }
        temp->next = newNode; // Link the previous node's next to the new node

        NodeCount++;  // Increment node count
    }
}

template <class T>
void DoublyLinkedList<T>::DeleteFirst()
{
    if(Head == NULL)           // If list is empty
    {
        cout << "Doubly Linked List is empty\n";
        return;
    }

    struct Node *temp = Head; // Temp pointer to hold the head

    Head = Head->next;         // Update head to the next node
    if (Head != NULL) 
    {
        Head->prev = NULL;      // Update new head's prev pointer to NULL
    }
    delete temp;               // Delete the old head
    NodeCount--;               // Decrement node count
}

template <class T>
void DoublyLinkedList<T>::DeleteLast()
{
    if(Head == NULL)           // If list is empty
    {
        cout << "Doubly Linked List is empty\n";
        return;
    }

    if(Head->next == NULL)     // If only one node in the list
    {
        delete Head;
        Head = NULL;
    }
    else                       // Traverse to the last node
    {
        struct Node *temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        delete temp;           // Delete the last node
        temp->prev->next = NULL; // Update second last node's next to NULL
    }
    NodeCount--;               // Decrement node count
}

template <class T>
void DoublyLinkedList<T>::DeleteAtPos(int position)
{
    if(position < 1 || position > NodeCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(position == 1)
    {
        DeleteFirst();        // If deleting the first node
    }
    else if(position == NodeCount)
    {
        DeleteLast();         // If deleting the last node
    }
    else
    {
        struct Node *temp = Head;

        for(int i = 1; i < position; i++)
        {
            temp = temp->next; // Traverse to the node to delete
        }

        struct Node *targetNode = temp; // Node to delete

        if (targetNode->next != NULL) 
        {
            targetNode->next->prev = targetNode->prev; // Bypass the node to delete
        }
        targetNode->prev->next = targetNode->next; // Bypass the node to delete
        delete targetNode;            // Delete the target node

        NodeCount--;                  // Decrement node count
    }
}

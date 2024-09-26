/////////////////////////////////////////////////////////////
// Singly Circular Linked List Implementation
// 
// Description: 
// This class represents a singly circular linked list using templates.
// It provides methods to insert, delete, and display nodes.
//
// Author: Om Karadkar
// Date: 10/04/2024
// Version: 1.0
/////////////////////////////////////////////////////////////

using namespace std;

template <class T>
class SinglyCircularLinkedList
{
    private:
        struct Node
        {
            T data;                    // Data part of the node
            struct Node *next; // Pointer to the next node
        };
        struct Node *Head; // Pointer to the first node (head)
        int NodeCount;                  // Count of the number of nodes

    public:
        // Constructor to initialize list
        SinglyCircularLinkedList();

        // Display all nodes
        void Display();

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
SinglyCircularLinkedList<T>::SinglyCircularLinkedList()
{
    Head = NULL; // Initialize head pointer to NULL
    NodeCount = 0; // Initialize node count to 0
}

template <class T>
void SinglyCircularLinkedList<T>::Display()
{
    if (Head == NULL) {
        cout << "Singly Circular Linked List is empty\n";
        return;
    }

    struct Node *temp = Head; // Temp pointer to traverse the list
    do {
        cout << "| " << temp->data << " | -> "; // Display node data
        temp = temp->next; // Move to the next node
    } while (temp != Head);
    
    cout << "Head\n"; // Indicate end of the circular list
}

template <class T>
int SinglyCircularLinkedList<T>::Count()
{
    return NodeCount; // Return the total count of nodes
}

template <class T>
void SinglyCircularLinkedList<T>::InsertFirst(T value)
{
    struct Node *newNode = new Node;

    newNode->data = value;     // Assign the data value

    if (Head == NULL) { // If the list is empty
        Head = newNode; // New node becomes the head
        newNode->next = Head; // Point to itself
    } else {
        struct Node *temp = Head;

        while (temp->next != Head) {
            temp = temp->next; // Traverse to the last node
        }

        temp->next = newNode;  // Last node's next points to new node
        newNode->next = Head;  // New node points to the head
        Head = newNode;        // Update head to new node
    }
    NodeCount++;               // Increment node count
}

template <class T>
void SinglyCircularLinkedList<T>::InsertLast(T value)
{
    struct Node *newNode = new Node;

    newNode->data = value;     // Assign the data value
    newNode->next = NULL;      // Not used, but keep for clarity

    if (Head == NULL) { // If the list is empty
        Head = newNode; // New node becomes the head
        newNode->next = Head; // Point to itself
    } else {
        struct Node *temp = Head;

        while (temp->next != Head) {
            temp = temp->next; // Traverse to the last node
        }

        temp->next = newNode;  // Last node's next points to new node
        newNode->next = Head;  // New node points to the head
    }
    NodeCount++;               // Increment node count
}

template <class T>
void SinglyCircularLinkedList<T>::InsertAtPos(T value, int position)
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
        temp->next = newNode;

        NodeCount++;  // Increment node count
    }
}

template <class T>
void SinglyCircularLinkedList<T>::DeleteFirst()
{
    if(Head == NULL)           // If list is empty
    {
        cout << "Singly Circular Linked List is empty\n";
        return;
    }

    struct Node *temp = Head; // Temp pointer to hold the head

    if (Head->next == Head)     // Only one node in the list
    { 
        delete Head;
        Head = NULL;
    } else 
    {
        struct Node *lastNode = Head;

        while(lastNode->next != Head) 
        {
            lastNode = lastNode->next; // Traverse to the last node
        }

        Head = Head->next;         // Update head to the next node
        lastNode->next = Head;     // Update last node's next to new head
        delete temp;               // Delete the old head
    }
    NodeCount--;               // Decrement node count
}

template <class T>
void SinglyCircularLinkedList<T>::DeleteLast()
{
    if(Head == NULL)           // If list is empty
    {
        cout << "Singly Circular Linked List is empty\n";
        return;
    }

    if(Head->next == Head)     // If only one node in the list
    {
        delete Head;
        Head = NULL;
    }
    else                       // Traverse to the second last node
    {
        struct Node *temp = Head;

        while(temp->next->next != Head)
        {
            temp = temp->next;
        }

        delete temp->next;     // Delete the last node
        temp->next = Head;     // Update second last node's next to head
    }
    NodeCount--;               // Decrement node count
}

template <class T>
void SinglyCircularLinkedList<T>::DeleteAtPos(int position)
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

        for(int i = 1; i < position - 1; i++)
        {
            temp = temp->next; // Traverse to the node before the deletion point
        }

        struct Node *targetNode = temp->next; // Node to delete

        temp->next = targetNode->next; // Bypass the node to delete
        delete targetNode;            // Delete the target node

        NodeCount--;                  // Decrement node count
    }
}


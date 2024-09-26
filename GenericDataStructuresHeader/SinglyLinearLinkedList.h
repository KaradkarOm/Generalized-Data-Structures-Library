/////////////////////////////////////////////////////////////
// Singly Linked List Implementation
// 
// Description: 
// This class represents a singly linked list using templates.
// It provides methods to insert, delete, and display nodes.
//
// Author: Om Karadkar
// Date: 10/04/2024
// Version: 1.0
/////////////////////////////////////////////////////////////


template <class T>
struct Node {
    T data;
    Node* next;
};

template <class T>
class SinglyLinearLinkedList
{
    private:
        Node<T> *Head; // Pointer to the first node (head)
        int NodeCount;                  // Count of the number of nodes

    public:
        // Constructor to initialize list
        SinglyLinearLinkedList();

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
SinglyLinearLinkedList<T>::SinglyLinearLinkedList()
{
    Head = NULL; // Initialize head pointer to NULL
    NodeCount = 0; // Initialize node count to 0
}

template <class T>
void SinglyLinearLinkedList<T>::Display()
{
    struct Node<T> *temp = Head; // Temp pointer to traverse the list

    while(temp != NULL)
    {
        cout << "| " << temp->data << "| -> "; // Display node data
        temp = temp->next; // Move to the next node
    }
    cout << "NULL\n"; // Indicate end of the list
}

template <class T>
int SinglyLinearLinkedList<T>::Count()
{
    return NodeCount; // Return the total count of nodes
}

template <class T>
void SinglyLinearLinkedList<T>::InsertFirst(T value)
{
    struct Node<T> *newNode = new Node<T>();

    newNode->data = value;     // Assign the data value
    newNode->next = Head;      // Point new node's next to current head
    Head = newNode;            // Update head to new node
    NodeCount++;               // Increment node count
}

template <class T>
void SinglyLinearLinkedList<T>::InsertLast(T value)
{
    struct Node<T> *newNode = new Node<T>;

    newNode->data = value;     // Assign the data value
    newNode->next = NULL;      // Last node's next is always NULL

    if(Head == NULL)           // If list is empty, make the new node the head
    {
        Head = newNode;
    }
    else                       // Traverse to the last node
    {
        struct Node<T> *temp = Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;  // Set last node's next to the new node
    }
    NodeCount++;               // Increment node count
}

template <class T>
void SinglyLinearLinkedList<T>::InsertAtPos(T value, int position)
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
        struct Node<T> *temp = Head;

        struct Node<T> *newNode = new Node<T>;
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
void SinglyLinearLinkedList<T>::DeleteFirst()
{
    if(Head == NULL)           // If list is empty
    {
        cout << "Singly Linked List is empty\n";
        return;
    }

    struct Node<T> *temp = Head; // Temp pointer to hold first node

    Head = Head->next;         // Update head to the next node
    delete temp;               // Delete the first node
    NodeCount--;               // Decrement node count
}

template <class T>
void SinglyLinearLinkedList<T>::DeleteLast()
{
    if(Head == NULL)           // If list is empty
    {
        cout << "Singly Linked List is empty\n";
        return;
    }

    if(Head->next == NULL)     // If only one node in the list
    {
        delete Head;
        Head = NULL;
    }
    else                       // Traverse to the second last node
    {
        struct Node<T> *temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;     // Delete the last node
        temp->next = NULL;     // Update second last node's next to NULL
    }
    NodeCount--;               // Decrement node count
}

template <class T>
void SinglyLinearLinkedList<T>::DeleteAtPos(int position)
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
        struct Node<T> *temp = Head;

        for(int i = 1; i < position - 1; i++)
        {
            temp = temp->next; // Traverse to the node before the deletion point
        }

        struct Node<T> *targetNode = temp->next; // Node to delete

        temp->next = targetNode->next; // Bypass the node to delete
        delete targetNode;            // Delete the target node

        NodeCount--;                  // Decrement node count
    }
}


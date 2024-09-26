/////////////////////////////////////////////////////////////
// Queue Implementation Using Singly Linked List
// 
// Description: 
// This class represents a queue using a singly linked list.
// It provides methods to enqueue, dequeue, peek, and check if the queue is empty.
//
// Author: Om Karadkar
// Date: 10/04/2024
// Version: 1.0
/////////////////////////////////////////////////////////////

using namespace std;

template <class T>
class Queue
{
private:
    struct Node
    {
        T data;             // Data part of the node
        Node* next;        // Pointer to the next node
    };

    Node* front;          // Pointer to the front node
    Node* rear;           // Pointer to the rear node
    int count;           // Count of elements in the queue

public:
    Queue();             // Constructor
    ~Queue();            // Destructor

    void enqueue(T value); // Add an element to the queue
    T dequeue();           // Remove an element from the queue
    T peek();              // Get the front element of the queue
    bool isEmpty();        // Check if the queue is empty
    int size();            // Get the number of elements in the queue
};

template <class T>
Queue<T>::Queue()
{
    front = NULL;     // Initialize front to NULL
    rear = NULL;      // Initialize rear to NULL
    count = 0;          // Initialize count to 0
}

template <class T>
Queue<T>::~Queue()
{
    while (!isEmpty())
    {
        dequeue();       // Free memory by dequeuing all elements
    }
}

template <class T>
void Queue<T>::enqueue(T value)
{
    Node* newNode = new Node; // Create a new node
    newNode->data = value;     // Set data
    newNode->next = NULL;   // New node will be the last node

    if (isEmpty())
    {
        front = newNode;       // If queue is empty, front and rear point to the new node
    }
    else
    {
        rear->next = newNode;  // Link the old rear to the new node
    }
    rear = newNode;            // Update rear to the new node
    count++;                   // Increment count
    cout << "Enqueued " << value << " to the queue.\n";
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow: Cannot dequeue from an empty queue.\n";
        return T(); // Return default value of T
    }

    T value = front->data;    // Get the front element
    Node* temp = front;       // Store the front node
    front = front->next;      // Update front to the next node

    if (front == NULL)      // If the queue is now empty
    {
        rear = NULL;       // Update rear to NULL
    }

    delete temp;              // Free memory
    count--;                  // Decrement count
    return value;             // Return dequeued value
}

template <class T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty: Cannot peek.\n";
        return T(); // Return default value of T
    }
    return front->data;       // Return the front element
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (count == 0);      // Return true if queue is empty
}

template <class T>
int Queue<T>::size()
{
    return count;             // Return the number of elements in the queue
}

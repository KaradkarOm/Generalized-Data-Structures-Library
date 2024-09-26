/////////////////////////////////////////////////////////////
// Stack Implementation Using Singly Linked List
// 
// Description: 
// This class represents a stack using a singly linked list.
// It provides methods to push, pop, and peek elements.
//
// Author: Om Karadkar
// Date: 10/04/2024
// Version: 1.0
/////////////////////////////////////////////////////////////

using namespace std;

template <class T>
class Stack
{
private:
    struct Node
    {
        T data;             // Data part of the node
        Node* next;        // Pointer to the next node
    };
    
    Node* top;            // Pointer to the top node
    int count;           // Count of elements in the stack

public:
    Stack();             // Constructor
    ~Stack();            // Destructor

    void push(T value);  // Add an element to the stack
    T pop();             // Remove an element from the stack
    T peek();            // Get the top element of the stack
    bool isEmpty();      // Check if the stack is empty
    int size();          // Get the number of elements in the stack
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;      // Initialize top to NULL
    count = 0;         // Initialize count to 0
}

template <class T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();          // Free memory by popping all elements
    }
}

template <class T>
void Stack<T>::push(T value)
{
    Node* newNode = new Node; // Create a new node
    newNode->data = value;    // Set data
    newNode->next = top;      // Point to the current top
    top = newNode;            // Update top to the new node
    count++;                  // Increment count
    cout << "Pushed " << value << " onto the stack.\n";
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow: Cannot pop from an empty stack.\n";
        return T(); // Return default value of T
    }
    
    T value = top->data;      // Get the top element
    Node* temp = top;         // Store the top node
    top = top->next;          // Update top to the next node
    delete temp;              // Free memory
    count--;                  // Decrement count
    return value;             // Return popped value
}

template <class T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty: Cannot peek.\n";
        return T(); // Return default value of T
    }
    return top->data;         // Return the top element
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (count == 0);      // Return true if stack is empty
}

template <class T>
int Stack<T>::size()
{
    return count;             // Return the number of elements in the stack
}


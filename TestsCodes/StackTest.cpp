#include <iostream>
#include "../include/Stack.h" // Include the header file for the stack

using namespace std;

int main()
{
    Stack<int> stack; // Create an instance of the stack

    // Hardcoded values to push onto the stack
    stack.push(10); // Push 10 onto the stack
    stack.push(20); // Push 20 onto the stack
    stack.push(30); // Push 30 onto the stack

    cout << "Top element is: " << stack.peek() << endl; // Peek the top element

    cout << "Stack size: " << stack.size() << endl; // Display the size of the stack

    cout << "Popping elements from the stack:\n";
    while (!stack.isEmpty())
    {
        cout << "Popped: " << stack.pop() << endl; // Pop elements until the stack is empty
    }

    // Trying to pop from an empty stack
    stack.pop(); // This should show an underflow message

    return 0;
}

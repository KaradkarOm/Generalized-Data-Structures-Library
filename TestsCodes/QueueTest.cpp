#include <iostream>
#include "../include/Queue.h" // Include the header file for the queue

using namespace std;

int main()
{
    Queue<int> queue; // Create an instance of the queue

    // Hardcoded values to enqueue into the queue
    queue.enqueue(10); // Enqueue 10
    queue.enqueue(20); // Enqueue 20
    queue.enqueue(30); // Enqueue 30

    cout << "Front element is: " << queue.peek() << endl; // Peek the front element

    cout << "Queue size: " << queue.size() << endl; // Display the size of the queue

    cout << "Dequeuing elements from the queue:\n";
    while (!queue.isEmpty())
    {
        cout << "Dequeued: " << queue.dequeue() << endl; // Dequeue elements until the queue is empty
    }

    // Trying to dequeue from an empty queue
    queue.dequeue(); // This should show an underflow message

    return 0;
}

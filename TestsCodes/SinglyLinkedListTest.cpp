#include <iostream>
using namespace std;
#include "../include/SinglyLinearLinkedList.h"  // Include the header file for SinglyLinearLinkedList

void testSinglyLinearLinkedList() {
    SinglyLinearLinkedList<int> list; // Create a SinglyLinearLinkedList for integers

    // Test InsertFirst
    std::cout << "Testing InsertFirst..." << std::endl;
    list.InsertFirst(10);
    list.InsertFirst(20);
    list.InsertFirst(30);
    std::cout << "After InsertFirst(30), InsertFirst(20), InsertFirst(10): ";
    list.Display(); // Expected: 30 -> 20 -> 10 -> nullptr

    // Test InsertLast
    std::cout << "Testing InsertLast..." << std::endl;
    list.InsertLast(40);
    list.InsertLast(50);
    std::cout << "After InsertLast(40), InsertLast(50): ";
    list.Display(); // Expected: 30 -> 20 -> 10 -> 40 -> 50 -> nullptr

    // Test InsertAtPos
    std::cout << "Testing InsertAtPos..." << std::endl;
    list.InsertAtPos(25, 3);
    list.InsertAtPos(35, 6);
    std::cout << "After InsertAtPos(25, 3) and InsertAtPos(35, 6): ";
    list.Display(); // Expected: 30 -> 20 -> 25 -> 10 -> 40 -> 35 -> 50 -> nullptr

    // Test DeleteFirst
    std::cout << "Testing DeleteFirst..." << std::endl;
    list.DeleteFirst();
    std::cout << "After DeleteFirst(): ";
    list.Display(); // Expected: 20 -> 25 -> 10 -> 40 -> 35 -> 50 -> nullptr

    // Test DeleteLast
    std::cout << "Testing DeleteLast..." << std::endl;
    list.DeleteLast();
    std::cout << "After DeleteLast(): ";
    list.Display(); // Expected: 20 -> 25 -> 10 -> 40 -> 35 -> nullptr

    // Test DeleteAtPos
    std::cout << "Testing DeleteAtPos..." << std::endl;
    list.DeleteAtPos(3);
    std::cout << "After DeleteAtPos(3): ";
    list.Display(); // Expected: 20 -> 25 -> 40 -> 35 -> nullptr

    // Test Count
    std::cout << "Testing Count function..." << std::endl;
    std::cout << "Node Count: " << list.Count() << std::endl; // Expected: 4

    // Test DeleteFirst again
    std::cout << "Testing DeleteFirst again..." << std::endl;
    list.DeleteFirst();
    std::cout << "After DeleteFirst(): ";
    list.Display(); // Expected: 25 -> 40 -> 35 -> nullptr

    // Test DeleteLast again
    std::cout << "Testing DeleteLast again..." << std::endl;
    list.DeleteLast();
    std::cout << "After DeleteLast(): ";
    list.Display(); // Expected: 25 -> 40 -> nullptr

    // Test DeleteAtPos again
    std::cout << "Testing DeleteAtPos again..." << std::endl;
    list.DeleteAtPos(1);
    std::cout << "After DeleteAtPos(1): ";
    list.Display(); // Expected: 40 -> nullptr

    // Test deleting the last element
    std::cout << "Testing DeleteLast on the last element..." << std::endl;
    list.DeleteLast();
    std::cout << "After DeleteLast(): ";
    list.Display(); // Expected: List is empty

    // Final count
    std::cout << "Final Node Count: " << list.Count() << std::endl; // Expected: 0
}

int main() {
    testSinglyLinearLinkedList(); // Run all the tests
    return 0;
}

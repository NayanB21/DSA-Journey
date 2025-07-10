#include <iostream>
using namespace std;

/*
IMPLEMENTING QUEUE FROM SCRATCH

Problem Statement:
Implement a Queue data structure using a singly linked list that supports the following operations:

Queue Operations:
- push(val): Add an element to the rear of the queue
- pop(): Remove an element from the front of the queue
- front(): Get the front element of the queue without removing it
- empty(): Check if the queue is empty

Queue Properties (FIFO - First In First Out):
1. Elements are added at the rear (tail)
2. Elements are removed from the front (head)
3. The first element added is the first element to be removed

Implementation Approach:
- Use singly linked list with head and tail pointers
- head points to the front of queue (for removal)
- tail points to the rear of queue (for insertion)
- When queue is empty, both head and tail are NULL

Time Complexity:
- push(): O(1) - Add at tail
- pop(): O(1) - Remove from head
- front(): O(1) - Access head data
- empty(): O(1) - Check if head is NULL

Space Complexity: O(n) where n is number of elements
*/

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

class Queue
{

public:
    Node *head;
    Node *tail;

    Queue()
    {
        head = tail = NULL;
    }

    // Add element to the rear of queue
    void push(int val)
    {
        Node *newNode = new Node(val);

        // If queue is empty, both head and tail point to new node
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            // Add new node at tail and update tail pointer
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove element from front of queue
    void pop()
    {
        // If queue is empty, nothing to remove
        if (head == NULL)
        {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        // If queue becomes empty after removal, update tail to NULL
        if (head == NULL)
        {
            tail = NULL;
        }

        delete temp;
    }

    // Get front element without removing it
    int front()
    {
        // If queue is empty, return -1 (or throw exception)
        if (head == NULL)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return head->data;
    }

    // Check if queue is empty
    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    cout << "=== QUEUE IMPLEMENTATION FROM SCRATCH - TEST CASES ===" << endl;

    // Test Case 1: Basic push and front operations
    cout << "\nTest Case 1: Basic push and front operations" << endl;
    Queue q1;
    cout << "Initial empty check: " << (q1.empty() ? "Empty" : "Not Empty") << endl;

    q1.push(10);
    q1.push(20);
    q1.push(30);

    cout << "After pushing 10, 20, 30:" << endl;
    cout << "Front element: " << q1.front() << " (Expected: 10)" << endl;
    cout << "Is empty: " << (q1.empty() ? "Yes" : "No") << " (Expected: No)" << endl;
    cout << "Result: " << (q1.front() == 10 && !q1.empty() ? "PASS" : "FAIL") << endl;

    // Test Case 2: Pop operations and FIFO behavior
    cout << "\nTest Case 2: Pop operations and FIFO behavior" << endl;
    Queue q2;
    q2.push(100);
    q2.push(200);
    q2.push(300);

    cout << "Queue: 100 -> 200 -> 300" << endl;

    int front1 = q2.front();
    q2.pop();
    int front2 = q2.front();
    q2.pop();
    int front3 = q2.front();
    q2.pop();

    cout << "Popped elements in order: " << front1 << ", " << front2 << ", " << front3 << endl;
    cout << "Expected order: 100, 200, 300" << endl;
    cout << "Is empty after all pops: " << (q2.empty() ? "Yes" : "No") << " (Expected: Yes)" << endl;
    cout << "Result: " << (front1 == 100 && front2 == 200 && front3 == 300 && q2.empty() ? "PASS" : "FAIL") << endl;

    // Test Case 3: Single element operations
    cout << "\nTest Case 3: Single element operations" << endl;
    Queue q3;
    q3.push(42);

    int singleFront = q3.front();
    bool emptyBefore = q3.empty();
    q3.pop();
    bool emptyAfter = q3.empty();

    cout << "Pushed single element 42" << endl;
    cout << "Front before pop: " << singleFront << " (Expected: 42)" << endl;
    cout << "Empty before pop: " << (emptyBefore ? "Yes" : "No") << " (Expected: No)" << endl;
    cout << "Empty after pop: " << (emptyAfter ? "Yes" : "No") << " (Expected: Yes)" << endl;
    cout << "Result: " << (singleFront == 42 && !emptyBefore && emptyAfter ? "PASS" : "FAIL") << endl;

    // Test Case 4: Pop from empty queue
    cout << "\nTest Case 4: Operations on empty queue" << endl;
    Queue q4;
    cout << "Attempting to pop from empty queue:" << endl;
    q4.pop(); // Should print error message

    cout << "Attempting to get front from empty queue:" << endl;
    int emptyFront = q4.front(); // Should print error and return -1

    cout << "Front returned: " << emptyFront << " (Expected: -1)" << endl;
    cout << "Result: " << (emptyFront == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Mixed operations
    cout << "\nTest Case 5: Mixed push and pop operations" << endl;
    Queue q5;

    // Push some elements
    q5.push(1);
    q5.push(2);
    int step1 = q5.front(); // Should be 1

    q5.pop(); // Remove 1
    q5.push(3);
    int step2 = q5.front(); // Should be 2

    q5.pop(); // Remove 2
    q5.push(4);
    int step3 = q5.front(); // Should be 3

    q5.pop();               // Remove 3
    int step4 = q5.front(); // Should be 4

    cout << "Mixed operations sequence:" << endl;
    cout << "Step results: " << step1 << ", " << step2 << ", " << step3 << ", " << step4 << endl;
    cout << "Expected: 1, 2, 3, 4" << endl;
    cout << "Result: " << (step1 == 1 && step2 == 2 && step3 == 3 && step4 == 4 ? "PASS" : "FAIL") << endl;

    cout << "\n=== ALL TEST CASES COMPLETED ===" << endl;

    return 0;
}

/*
Problem: Min Stack
Description: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Example:
Input: ["MinStack","push","push","push","getMin","pop","top","getMin"]
       [[],[-2],[0],[-3],[],[],[],[]]
Output: [null,null,null,null,-3,null,0,-2]

Time Complexity: O(1) for all operations
Space Complexity: O(n) where n is the number of elements
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
    vector<int> vec;
    stack<int> s; // Stack to keep track of minimum elements

public:
    MinStack()
    {
        vec = {};
    }

    void push(int val)
    {
        vec.push_back(val);

        // If it's the first element or val is smaller than or equal to current min
        if (vec.size() == 1)
        {
            s.push(val);
        }
        else if (val <= s.top())
        {
            s.push(val);
        }
    }

    void pop()
    {
        // If the element being popped is the current minimum, pop from min stack too
        if (vec[vec.size() - 1] == s.top())
        {
            s.pop();
        }
        vec.pop_back();
    }

    int top()
    {
        return vec[vec.size() - 1];
    }

    int getMin()
    {
        return s.top();
    }
};

int main()
{
    // Test Case 1: Basic operations
    cout << "Test 1: Basic operations" << endl;
    MinStack *minStack1 = new MinStack();
    minStack1->push(-2);
    minStack1->push(0);
    minStack1->push(-3);
    cout << "After push(-2), push(0), push(-3):" << endl;
    cout << "getMin(): " << minStack1->getMin() << ", Expected: -3" << endl;
    minStack1->pop();
    cout << "After pop():" << endl;
    cout << "top(): " << minStack1->top() << ", Expected: 0" << endl;
    cout << "getMin(): " << minStack1->getMin() << ", Expected: -2" << endl
         << endl;
    delete minStack1;

    // Test Case 2: Duplicate minimum values
    cout << "Test 2: Duplicate minimum values" << endl;
    MinStack *minStack2 = new MinStack();
    minStack2->push(1);
    minStack2->push(1);
    minStack2->push(1);
    cout << "After push(1), push(1), push(1):" << endl;
    cout << "getMin(): " << minStack2->getMin() << ", Expected: 1" << endl;
    minStack2->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack2->getMin() << ", Expected: 1" << endl;
    cout << "top(): " << minStack2->top() << ", Expected: 1" << endl
         << endl;
    delete minStack2;

    // Test Case 3: Decreasing sequence
    cout << "Test 3: Decreasing sequence" << endl;
    MinStack *minStack3 = new MinStack();
    minStack3->push(5);
    minStack3->push(3);
    minStack3->push(1);
    cout << "After push(5), push(3), push(1):" << endl;
    cout << "getMin(): " << minStack3->getMin() << ", Expected: 1" << endl;
    minStack3->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack3->getMin() << ", Expected: 3" << endl;
    minStack3->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack3->getMin() << ", Expected: 5" << endl
         << endl;
    delete minStack3;

    // Test Case 4: Mixed operations
    cout << "Test 4: Mixed operations" << endl;
    MinStack *minStack4 = new MinStack();
    minStack4->push(2);
    minStack4->push(1);
    minStack4->push(3);
    cout << "After push(2), push(1), push(3):" << endl;
    cout << "getMin(): " << minStack4->getMin() << ", Expected: 1" << endl;
    cout << "top(): " << minStack4->top() << ", Expected: 3" << endl;
    minStack4->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack4->getMin() << ", Expected: 1" << endl;
    cout << "top(): " << minStack4->top() << ", Expected: 1" << endl
         << endl;
    delete minStack4;

    // Test Case 5: Single element
    cout << "Test 5: Single element" << endl;
    MinStack *minStack5 = new MinStack();
    minStack5->push(42);
    cout << "After push(42):" << endl;
    cout << "top(): " << minStack5->top() << ", Expected: 42" << endl;
    cout << "getMin(): " << minStack5->getMin() << ", Expected: 42" << endl;
    minStack5->pop();
    cout << "After pop(): Stack is empty" << endl
         << endl;
    delete minStack5;

    return 0;
}
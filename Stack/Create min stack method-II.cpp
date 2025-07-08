/*
Problem: Min Stack (Space Optimized Method)
Description: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time using only one stack.

This is an optimized approach that uses mathematical encoding to store both the actual value and minimum information in a single stack, reducing space complexity.

Algorithm:
- When pushing a value smaller than current minimum, store an encoded value: 2*val - minVal
- The encoded value is always smaller than the new minimum
- When popping, if top < minVal, it means it's encoded, so decode the previous minimum: 2*minVal - top
- When getting top, if top < minVal, return minVal (the actual value), else return top

Time Complexity: O(1) for all operations
Space Complexity: O(n) where n is the number of elements (single stack only)
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    stack<long long int> s;
    long long int minVal;

public:
    MinStack()
    {
        // Constructor - no initialization needed
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            minVal = val;
        }
        else if (val < minVal)
        {
            // Store encoded value when new minimum is found
            s.push((long long)2 * val - minVal);
            minVal = val;
        }
        else
        {
            s.push(val);
        }
    }

    void pop()
    {
        if (s.top() < minVal)
        {
            // Decode previous minimum value
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }

    int top()
    {
        if (s.top() < minVal)
        {
            return minVal; // Return actual minimum value
        }
        else
        {
            return s.top();
        }
    }

    int getMin()
    {
        return minVal;
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

    // Test Case 2: Multiple minimums
    cout << "Test 2: Multiple minimums" << endl;
    MinStack *minStack2 = new MinStack();
    minStack2->push(5);
    minStack2->push(3);
    minStack2->push(1);
    minStack2->push(4);
    cout << "After push(5), push(3), push(1), push(4):" << endl;
    cout << "getMin(): " << minStack2->getMin() << ", Expected: 1" << endl;
    cout << "top(): " << minStack2->top() << ", Expected: 4" << endl;
    minStack2->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack2->getMin() << ", Expected: 1" << endl;
    cout << "top(): " << minStack2->top() << ", Expected: 1" << endl
         << endl;
    delete minStack2;

    // Test Case 3: Decreasing sequence
    cout << "Test 3: Decreasing sequence" << endl;
    MinStack *minStack3 = new MinStack();
    minStack3->push(10);
    minStack3->push(5);
    minStack3->push(1);
    cout << "After push(10), push(5), push(1):" << endl;
    cout << "getMin(): " << minStack3->getMin() << ", Expected: 1" << endl;
    minStack3->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack3->getMin() << ", Expected: 5" << endl;
    minStack3->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack3->getMin() << ", Expected: 10" << endl
         << endl;
    delete minStack3;

    // Test Case 4: Same values
    cout << "Test 4: Same values" << endl;
    MinStack *minStack4 = new MinStack();
    minStack4->push(2);
    minStack4->push(2);
    minStack4->push(2);
    cout << "After push(2), push(2), push(2):" << endl;
    cout << "getMin(): " << minStack4->getMin() << ", Expected: 2" << endl;
    cout << "top(): " << minStack4->top() << ", Expected: 2" << endl;
    minStack4->pop();
    cout << "After pop():" << endl;
    cout << "getMin(): " << minStack4->getMin() << ", Expected: 2" << endl
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
#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    int size;
    queue<int> main;
    queue<int> helper;
    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {
        main.push(x);
        helper = main;
        size++;
    }

    int pop()
    {
        if (size == 0)
            return -1; // Handle empty stack

        while (!main.empty())
            main.pop();

        for (int i = 0; i < size - 1; i++)
        {
            main.push(helper.front());
            helper.pop();
        }
        int ans2 = helper.front();
        helper.pop(); // Fix: Remove the popped element from helper
        helper = main;
        size--;
        return ans2;
    }

    int top()
    {
        if (size == 0)
            return -1; // Handle empty stack

        for (int i = 0; i < size - 1; i++)
            main.pop();

        int ans1 = main.front();
        main = helper;
        return ans1;
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    cout << "=== Stack using Queues Test Cases ===\n\n";

    // Test Case 1: Basic push and pop operations
    cout << "Test Case 1: Basic push and pop operations\n";
    MyStack *stack1 = new MyStack();
    stack1->push(10);
    stack1->push(20);
    stack1->push(30);
    cout << "After pushing 10, 20, 30\n";
    cout << "Top: " << stack1->top() << endl;
    cout << "Pop: " << stack1->pop() << endl;
    cout << "Top after pop: " << stack1->top() << endl;
    cout << "Empty: " << (stack1->empty() ? "true" : "false") << endl
         << endl;

    // Test Case 2: Empty stack operations
    cout << "Test Case 2: Empty stack operations\n";
    MyStack *stack2 = new MyStack();
    cout << "Empty stack - Empty: " << (stack2->empty() ? "true" : "false") << endl;
    cout << "Top of empty stack: " << stack2->top() << endl;
    cout << "Pop from empty stack: " << stack2->pop() << endl
         << endl;

    // Test Case 3: Single element operations
    cout << "Test Case 3: Single element operations\n";
    MyStack *stack3 = new MyStack();
    stack3->push(42);
    cout << "After pushing 42\n";
    cout << "Top: " << stack3->top() << endl;
    cout << "Empty: " << (stack3->empty() ? "true" : "false") << endl;
    cout << "Pop: " << stack3->pop() << endl;
    cout << "Empty after pop: " << (stack3->empty() ? "true" : "false") << endl
         << endl;

    // Test Case 4: Multiple operations
    cout << "Test Case 4: Multiple push/pop sequence\n";
    MyStack *stack4 = new MyStack();
    stack4->push(1);
    stack4->push(2);
    cout << "Pop: " << stack4->pop() << endl; // Should be 2
    stack4->push(3);
    stack4->push(4);
    cout << "Top: " << stack4->top() << endl; // Should be 4
    cout << "Pop: " << stack4->pop() << endl; // Should be 4
    cout << "Pop: " << stack4->pop() << endl; // Should be 3
    cout << "Top: " << stack4->top() << endl; // Should be 1
    cout << endl;

    // Test Case 5: LIFO behavior verification
    cout << "Test Case 5: LIFO behavior verification\n";
    MyStack *stack5 = new MyStack();
    for (int i = 1; i <= 5; i++)
    {
        stack5->push(i * 10);
        cout << "Pushed: " << i * 10 << ", Top: " << stack5->top() << endl;
    }
    cout << "Popping all elements: ";
    while (!stack5->empty())
    {
        cout << stack5->pop() << " ";
    }
    cout << endl;

    // Clean up
    delete stack1;
    delete stack2;
    delete stack3;
    delete stack4;
    delete stack5;

    return 0;
}
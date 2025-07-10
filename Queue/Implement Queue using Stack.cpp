#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    int size;
    stack<int> main;
    stack<int> helper;

    MyQueue()
    {
        size = 0;
    }

    void push(int x)
    {
        while (!main.empty())
        {
            helper.push(main.top());
            main.pop();
        }
        main.push(x);
        while (!helper.empty())
        {
            main.push(helper.top());
            helper.pop();
        }

        size++;
    }

    int pop()
    {
        if (size == 0)
            return -1; // Handle empty queue
        int ans = main.top();
        main.pop();
        size--;
        return ans;
    }

    int peek()
    {
        if (size == 0)
            return -1; // Handle empty queue
        return main.top();
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    cout << "=== Queue using Stacks Test Cases ===\n\n";

    // Test Case 1: Basic push and pop operations (FIFO)
    cout << "Test Case 1: Basic FIFO operations\n";
    MyQueue *queue1 = new MyQueue();
    queue1->push(10);
    queue1->push(20);
    queue1->push(30);
    cout << "After pushing 10, 20, 30\n";
    cout << "Peek: " << queue1->peek() << endl;           // Should be 10
    cout << "Pop: " << queue1->pop() << endl;             // Should be 10
    cout << "Peek after pop: " << queue1->peek() << endl; // Should be 20
    cout << "Empty: " << (queue1->empty() ? "true" : "false") << endl
         << endl;

    // Test Case 2: Empty queue operations
    cout << "Test Case 2: Empty queue operations\n";
    MyQueue *queue2 = new MyQueue();
    cout << "Empty queue - Empty: " << (queue2->empty() ? "true" : "false") << endl;
    cout << "Peek of empty queue: " << queue2->peek() << endl;
    cout << "Pop from empty queue: " << queue2->pop() << endl
         << endl;

    // Test Case 3: Single element operations
    cout << "Test Case 3: Single element operations\n";
    MyQueue *queue3 = new MyQueue();
    queue3->push(42);
    cout << "After pushing 42\n";
    cout << "Peek: " << queue3->peek() << endl;
    cout << "Empty: " << (queue3->empty() ? "true" : "false") << endl;
    cout << "Pop: " << queue3->pop() << endl;
    cout << "Empty after pop: " << (queue3->empty() ? "true" : "false") << endl
         << endl;

    // Test Case 4: Alternating push/pop operations
    cout << "Test Case 4: Alternating push/pop sequence\n";
    MyQueue *queue4 = new MyQueue();
    queue4->push(1);
    queue4->push(2);
    cout << "Pop: " << queue4->pop() << endl; // Should be 1
    queue4->push(3);
    queue4->push(4);
    cout << "Peek: " << queue4->peek() << endl; // Should be 2
    cout << "Pop: " << queue4->pop() << endl;   // Should be 2
    cout << "Pop: " << queue4->pop() << endl;   // Should be 3
    cout << "Peek: " << queue4->peek() << endl; // Should be 4
    cout << endl;

    // Test Case 5: FIFO behavior verification
    cout << "Test Case 5: FIFO behavior verification\n";
    MyQueue *queue5 = new MyQueue();
    cout << "Pushing elements 100, 200, 300, 400, 500:\n";
    for (int i = 1; i <= 5; i++)
    {
        int val = i * 100;
        queue5->push(val);
        cout << "Pushed: " << val << ", Front (peek): " << queue5->peek() << endl;
    }
    cout << "Popping all elements (should be in order 100, 200, 300, 400, 500): ";
    while (!queue5->empty())
    {
        cout << queue5->pop() << " ";
    }
    cout << endl;

    // Clean up
    delete queue1;
    delete queue2;
    delete queue3;
    delete queue4;
    delete queue5;

    return 0;
}
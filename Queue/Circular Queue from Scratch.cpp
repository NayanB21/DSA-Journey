#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {

public:
    vector<int> vec;
    int f, r, currSize, cap;

    CircularQueue(int cap) {
        vec.resize(cap);
        this->cap = cap;
        currSize = 0;
        f = 0;    // front points to the current first element
        r = -1;   // rear is where the last element was inserted
    }

    void push(int val) {
        if (currSize == cap) {
            cout << "size limits\n";
            return;
        }
        r = (r + 1) % cap;
        vec[r] = val;
        currSize++;
    }

    void pop() {
        if (currSize == 0) return;
        f = (f + 1) % cap;
        currSize--;
    }

    int front() {
        if (currSize == 0) return -1;
        return vec[f];
    }

    void printCircularQueue() {
        if (currSize == 0) {
            cout << "Queue is empty\n";
            return;
        }

        // safer version using currSize instead of relying on f, r alone
        int i = f;
        int count = 0;
        while (count < currSize) {
            cout << vec[i] << " ";
            i = (i + 1) % cap;
            count++;
        }
        cout << endl;
    }
};

// ---------------------- MAIN FUNCTION ----------------------

int main() {
    // Test Case 1: Basic Push and Print
    cout << "Test Case 1:\n";
    CircularQueue q1(5);
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.printCircularQueue(); // Expected: 10 20 30

    // Test Case 2: Push > Pop > Push (check wrap-around)
    cout << "Test Case 2:\n";
    CircularQueue q2(3);
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.pop();
    q2.push(4);
    q2.printCircularQueue(); // Expected: 2 3 4

    // Test Case 3: Pop until empty, then push
    cout << "Test Case 3:\n";
    CircularQueue q3(3);
    q3.push(5);
    q3.push(6);
    q3.pop();
    q3.pop();
    q3.printCircularQueue(); // Expected: Queue is empty
    q3.push(7);
    q3.printCircularQueue(); // Expected: 7

    // Test Case 4: Push more than capacity
    cout << "Test Case 4:\n";
    CircularQueue q4(2);
    q4.push(11);
    q4.push(12);
    q4.push(13);  // Expected: size limits
    q4.printCircularQueue(); // Expected: 11 12

    // Test Case 5: Continuous wrap-around
    cout << "Test Case 5:\n";
    CircularQueue q5(4);
    q5.push(100);
    q5.push(200);
    q5.push(300);
    q5.push(400);
    q5.pop();       // Remove 100
    q5.pop();       // Remove 200
    q5.push(500);
    q5.push(600);
    q5.printCircularQueue(); // Expected: 300 400 500 600

    return 0;
}

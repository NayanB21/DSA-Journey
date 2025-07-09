#include <iostream>
#include <unordered_map>
using namespace std;

/*
DESIGN LRU CACHE

Problem Statement:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
- LRUCache(int capacity): Initialize the LRU cache with positive size capacity
- int get(int key): Return the value of the key if the key exists, otherwise return -1
- void put(int key, int value): Update the value of the key if exists, otherwise add the key-value pair

When the cache reaches its capacity, it should invalidate and remove the least recently used key
before inserting a new item.

The functions get and put must each run in O(1) average time complexity.

Algorithm Approach:
1. Use a doubly linked list to maintain the order of usage (most recent to least recent)
2. Use a hashmap to store key -> node mapping for O(1) access
3. Head of list represents most recently used, tail represents least recently used
4. For get(): Move accessed node to head
5. For put(): Add new node to head, remove LRU node if capacity exceeded

Key Operations:
- addNode(): Add node right after head
- delNode(): Remove a node from its current position
- get(): Return value and move to head
- put(): Add/update and move to head, remove LRU if needed

Time Complexity: O(1) for both get and put operations
Space Complexity: O(capacity)
*/

class LRUCache
{

public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            next = prev = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> m;
    int limit;

    // Helper function to add a new node right after the head (most recently used position)
    void addNode(Node *newNode)
    {
        Node *temp = head->next; // Store current first node
        head->next = newNode;    // Head now points to new node
        temp->prev = newNode;    // Previous first node's prev points to new node
        newNode->next = temp;    // New node's next points to previous first node
        newNode->prev = head;    // New node's prev points to head
    }

    // Helper function to remove a node from its current position in the doubly linked list
    void delNode(Node *oldNode)
    {
        Node *tempPrev = oldNode->prev; // Store previous node
        Node *tempNext = oldNode->next; // Store next node

        // Connect previous and next nodes, effectively removing oldNode
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
    }

    // Constructor: Initialize LRU cache with given capacity
    LRUCache(int capacity)
    {
        limit = capacity;  // Set cache capacity
        head->next = tail; // Initially head points to tail
        tail->prev = head; // Initially tail points back to head
    }

    // Get operation: Return value if key exists, move to most recently used position
    int get(int key)
    {
        // Check if key exists in hashmap
        if (m.find(key) == m.end())
            return -1; // Key not found, return -1

        int ans = m[key]->value; // Get the value to return
        Node *ansNode = m[key];  // Get pointer to the node
        m.erase(key);            // Temporarily remove from hashmap

        // Move node to most recently used position (right after head)
        delNode(ansNode); // Remove from current position
        addNode(ansNode); // Add right after head
        m[key] = ansNode; // Update hashmap with new position
        return ans;       // Return the value
    }

    // Put operation: Add/update key-value pair, maintain capacity constraint
    void put(int key, int value)
    {
        // If key already exists, remove the old node
        if (m.find(key) != m.end())
        {
            delNode(m[key]); // Remove old node from list
            m.erase(key);    // Remove from hashmap
        }

        // If cache is at capacity, remove least recently used item (before tail)
        if (m.size() == limit)
        {
            // Delete LRU data (node just before tail)
            m.erase(tail->prev->key); // Remove from hashmap first
            delNode(tail->prev);      // Remove from doubly linked list
        }

        // Create new node and add to most recently used position
        Node *newNode = new Node(key, value); // Create new node
        addNode(newNode);                     // Add right after head
        m[key] = newNode;                     // Add to hashmap
    }
};

int main()
{
    cout << "=== LRU CACHE DESIGN - TEST CASES ===" << endl;

    // Test Case 1: Basic operations with capacity 2
    cout << "\nTest Case 1: Basic operations (capacity=2)" << endl;
    LRUCache *lru1 = new LRUCache(2);
    lru1->put(1, 1);
    lru1->put(2, 2);
    int result1_1 = lru1->get(1); // Should return 1
    lru1->put(3, 3);              // Evicts key 2
    int result1_2 = lru1->get(2); // Should return -1 (not found)
    lru1->put(4, 4);              // Evicts key 1
    int result1_3 = lru1->get(1); // Should return -1 (not found)
    int result1_4 = lru1->get(3); // Should return 3
    int result1_5 = lru1->get(4); // Should return 4

    cout << "Operations: put(1,1), put(2,2), get(1), put(3,3), get(2), put(4,4), get(1), get(3), get(4)" << endl;
    cout << "Expected: 1, -1, -1, 3, 4" << endl;
    cout << "Got: " << result1_1 << ", " << result1_2 << ", " << result1_3 << ", " << result1_4 << ", " << result1_5 << endl;
    cout << "Result: " << ((result1_1 == 1 && result1_2 == -1 && result1_3 == -1 && result1_4 == 3 && result1_5 == 4) ? "PASS" : "FAIL") << endl;

    // Test Case 2: Update existing key
    cout << "\nTest Case 2: Update existing key (capacity=2)" << endl;
    LRUCache *lru2 = new LRUCache(2);
    lru2->put(1, 1);
    lru2->put(2, 2);
    lru2->put(1, 10);             // Update key 1
    int result2_1 = lru2->get(1); // Should return 10
    int result2_2 = lru2->get(2); // Should return 2

    cout << "Operations: put(1,1), put(2,2), put(1,10), get(1), get(2)" << endl;
    cout << "Expected: 10, 2" << endl;
    cout << "Got: " << result2_1 << ", " << result2_2 << endl;
    cout << "Result: " << ((result2_1 == 10 && result2_2 == 2) ? "PASS" : "FAIL") << endl;

    // Test Case 3: Single capacity cache
    cout << "\nTest Case 3: Single capacity cache (capacity=1)" << endl;
    LRUCache *lru3 = new LRUCache(1);
    lru3->put(2, 1);
    int result3_1 = lru3->get(2); // Should return 1
    lru3->put(3, 2);              // Evicts key 2
    int result3_2 = lru3->get(2); // Should return -1
    int result3_3 = lru3->get(3); // Should return 2

    cout << "Operations: put(2,1), get(2), put(3,2), get(2), get(3)" << endl;
    cout << "Expected: 1, -1, 2" << endl;
    cout << "Got: " << result3_1 << ", " << result3_2 << ", " << result3_3 << endl;
    cout << "Result: " << ((result3_1 == 1 && result3_2 == -1 && result3_3 == 2) ? "PASS" : "FAIL") << endl;

    // Test Case 4: Get operation updates LRU order
    cout << "\nTest Case 4: Get updates LRU order (capacity=3)" << endl;
    LRUCache *lru4 = new LRUCache(3);
    lru4->put(1, 1);
    lru4->put(2, 2);
    lru4->put(3, 3);
    lru4->get(1);                 // Makes 1 most recently used
    lru4->put(4, 4);              // Should evict 2 (least recently used)
    int result4_1 = lru4->get(1); // Should return 1
    int result4_2 = lru4->get(2); // Should return -1 (evicted)
    int result4_3 = lru4->get(3); // Should return 3
    int result4_4 = lru4->get(4); // Should return 4

    cout << "Operations: put(1,1), put(2,2), put(3,3), get(1), put(4,4), get(1), get(2), get(3), get(4)" << endl;
    cout << "Expected: 1, -1, 3, 4" << endl;
    cout << "Got: " << result4_1 << ", " << result4_2 << ", " << result4_3 << ", " << result4_4 << endl;
    cout << "Result: " << ((result4_1 == 1 && result4_2 == -1 && result4_3 == 3 && result4_4 == 4) ? "PASS" : "FAIL") << endl;

    // Test Case 5: Large capacity with multiple operations
    cout << "\nTest Case 5: Multiple operations (capacity=4)" << endl;
    LRUCache *lru5 = new LRUCache(4);
    lru5->put(1, 100);
    lru5->put(2, 200);
    lru5->put(3, 300);
    lru5->put(4, 400);
    int result5_1 = lru5->get(1); // 100
    lru5->put(5, 500);            // Evicts 2
    int result5_2 = lru5->get(2); // -1
    lru5->put(6, 600);            // Evicts 3
    int result5_3 = lru5->get(3); // -1
    int result5_4 = lru5->get(4); // 400
    int result5_5 = lru5->get(5); // 500
    int result5_6 = lru5->get(6); // 600

    cout << "Complex operations with capacity 4" << endl;
    cout << "Expected: 100, -1, -1, 400, 500, 600" << endl;
    cout << "Got: " << result5_1 << ", " << result5_2 << ", " << result5_3 << ", " << result5_4 << ", " << result5_5 << ", " << result5_6 << endl;
    cout << "Result: " << ((result5_1 == 100 && result5_2 == -1 && result5_3 == -1 && result5_4 == 400 && result5_5 == 500 && result5_6 == 600) ? "PASS" : "FAIL") << endl;

    cout << "\n=== ALL TEST CASES COMPLETED ===" << endl;

    return 0;
}
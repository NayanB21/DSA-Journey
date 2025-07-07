/*
Problem: Previous Smaller Element
Description: Given an array of integers, find the previous smaller element for each element.
For each element, find the nearest smaller element to its left. If no such element exists, return -1.

Example:
Input: [4, 5, 2, 10, 8]
Output: [-1, 4, -1, 2, 2]

Explanation:
- For 4: No smaller element to the left, so -1
- For 5: 4 is the previous smaller element
- For 2: No smaller element to the left, so -1
- For 10: 2 is the previous smaller element
- For 8: 2 is the previous smaller element

Time Complexity: O(n) where n is the size of the array
Space Complexity: O(n) for the stack
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> previousSmallerElement(vector<int> &arr)
    {
        stack<int> s;
        vector<int> ans;

        // Process array from left to right
        for (int i = 0; i < arr.size(); i++)
        {
            // Pop elements from stack that are greater than or equal to current element
            while (!s.empty() && arr[i] <= s.top())
            {
                s.pop();
            }

            // If stack is empty, no smaller element exists
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }

            // Push current element to stack
            s.push(arr[i]);
        }

        return ans;
    }
};

// Helper function to print vector
void printVector(const vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    Solution solution;

    // Test Case 1: Basic example
    cout << "Test 1: Basic example" << endl;
    vector<int> arr1 = {4, 5, 2, 10, 8};
    vector<int> result1 = solution.previousSmallerElement(arr1);
    cout << "Input: [4, 5, 2, 10, 8]" << endl;
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [-1, 4, -1, 2, 2]" << endl
         << endl;

    // Test Case 2: Increasing array
    cout << "Test 2: Increasing array" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> result2 = solution.previousSmallerElement(arr2);
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    cout << "Expected: [-1, 1, 2, 3, 4]" << endl
         << endl;

    // Test Case 3: Decreasing array
    cout << "Test 3: Decreasing array" << endl;
    vector<int> arr3 = {5, 4, 3, 2, 1};
    vector<int> result3 = solution.previousSmallerElement(arr3);
    cout << "Input: [5, 4, 3, 2, 1]" << endl;
    cout << "Output: ";
    printVector(result3);
    cout << endl;
    cout << "Expected: [-1, -1, -1, -1, -1]" << endl
         << endl;

    // Test Case 4: Single element
    cout << "Test 4: Single element" << endl;
    vector<int> arr4 = {42};
    vector<int> result4 = solution.previousSmallerElement(arr4);
    cout << "Input: [42]" << endl;
    cout << "Output: ";
    printVector(result4);
    cout << endl;
    cout << "Expected: [-1]" << endl
         << endl;

    // Test Case 5: Array with duplicates
    cout << "Test 5: Array with duplicates" << endl;
    vector<int> arr5 = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result5 = solution.previousSmallerElement(arr5);
    cout << "Input: [3, 1, 4, 1, 5, 9, 2, 6]" << endl;
    cout << "Output: ";
    printVector(result5);
    cout << endl;
    cout << "Expected: [-1, -1, 1, -1, 1, 1, 1, 2]" << endl
         << endl;

    return 0;
}

/*
Problem: Trapping Rain Water
Description: Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map can trap 6 units of rain water.

Algorithm (Custom Approach):
1. Find nextGreaterOrEqual for each element (next bar that can hold water)
2. Find prevGreater for each element (previous bar that can hold water)
3. Process from left: calculate water trapped between current bar and next greater bar
4. Process from right: calculate water trapped between current bar and previous greater bar
5. Sum up all trapped water

Time Complexity: O(n) where n is the number of bars
Space Complexity: O(n) for the stacks and arrays
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int water = 0;
        int n = height.size();
        stack<int> s;

        // Find nextGreaterOrEqual elements
        vector<int> nextGreaterOrEqual(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && height[i] > height[s.top()])
            {
                s.pop();
            }

            nextGreaterOrEqual[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty())
            s.pop();

        // Find prevGreater elements
        vector<int> prevGreater(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && height[i] >= height[s.top()])
            {
                s.pop();
            }

            prevGreater[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Process from left to right
        int i = 0;
        while (i < n)
        {
            if (nextGreaterOrEqual[i] > 0)
            {
                // Calculate potential water area
                water += height[i] * (nextGreaterOrEqual[i] - i - 1);

                // Subtract the heights of bars in between
                for (int j = i + 1; j < nextGreaterOrEqual[i]; j++)
                {
                    water -= height[j];
                }

                i = nextGreaterOrEqual[i];
            }
            else
            {
                break;
            }
        }

        // Process from right to left
        i = n - 1;
        while (i >= 0)
        {
            if (prevGreater[i] >= 0)
            {
                // Calculate potential water area
                water += height[i] * (i - prevGreater[i] - 1);

                // Subtract the heights of bars in between
                for (int j = i - 1; j > prevGreater[i]; j--)
                {
                    water -= height[j];
                }

                i = prevGreater[i];
            }
            else
            {
                break;
            }
        }

        return water;
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

    // Test Case 1: Classic example
    cout << "Test 1: Classic example" << endl;
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result1 = solution.trap(height1);
    cout << "Input: ";
    printVector(height1);
    cout << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 6" << endl
         << endl;

    // Test Case 2: Simple valley
    cout << "Test 2: Simple valley" << endl;
    vector<int> height2 = {3, 0, 2, 0, 4};
    int result2 = solution.trap(height2);
    cout << "Input: ";
    printVector(height2);
    cout << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 7" << endl
         << endl;

    // Test Case 3: No water trapped
    cout << "Test 3: No water trapped (increasing)" << endl;
    vector<int> height3 = {1, 2, 3, 4, 5};
    int result3 = solution.trap(height3);
    cout << "Input: ";
    printVector(height3);
    cout << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 0" << endl
         << endl;

    // Test Case 4: Single deep valley
    cout << "Test 4: Single deep valley" << endl;
    vector<int> height4 = {4, 2, 3};
    int result4 = solution.trap(height4);
    cout << "Input: ";
    printVector(height4);
    cout << endl;
    cout << "Output: " << result4 << endl;
    cout << "Expected: 1" << endl
         << endl;

    // Test Case 5: Multiple valleys
    cout << "Test 5: Multiple valleys" << endl;
    vector<int> height5 = {2, 0, 2, 0, 2};
    int result5 = solution.trap(height5);
    cout << "Input: ";
    printVector(height5);
    cout << endl;
    cout << "Output: " << result5 << endl;
    cout << "Expected: 4" << endl
         << endl;

    return 0;
}
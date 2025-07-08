/*
Problem: Largest Rectangle in Histogram
Description: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

Example:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The largest rectangle is formed by heights [5,6] with width 2, so area = 5 * 2 = 10.

Algorithm:
1. For each bar, find the nearest smaller element on the left (prevSmall)
2. For each bar, find the nearest smaller element on the right (nextSmall)
3. For each bar, calculate rectangle area: height[i] * (nextSmall[i] - prevSmall[i] - 1)
4. Return the maximum area

Time Complexity: O(n) where n is the number of bars
Space Complexity: O(n) for the stacks and arrays
*/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int n = heights.size();

        // Creating vector: nextSmall (next smaller element indices)
        vector<int> nextSmall(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                nextSmall[i] = n; // No right boundary, use n
            }
            else
            {
                nextSmall[i] = s.top();
            }
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty())
            s.pop();

        // Creating vector: prevSmall (previous smaller element indices)
        vector<int> prevSmall(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                prevSmall[i] = -1; // No left boundary, use -1
            }
            else
            {
                prevSmall[i] = s.top();
            }
            s.push(i);
        }

        // Calculate maximum rectangle area
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (nextSmall[i] - prevSmall[i] - 1));
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
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    int result1 = solution.largestRectangleArea(heights1);
    cout << "Input: ";
    printVector(heights1);
    cout << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 10" << endl
         << endl;

    // Test Case 2: Increasing heights
    cout << "Test 2: Increasing heights" << endl;
    vector<int> heights2 = {1, 2, 3, 4, 5};
    int result2 = solution.largestRectangleArea(heights2);
    cout << "Input: ";
    printVector(heights2);
    cout << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 9" << endl
         << endl;

    // Test Case 3: Decreasing heights
    cout << "Test 3: Decreasing heights" << endl;
    vector<int> heights3 = {5, 4, 3, 2, 1};
    int result3 = solution.largestRectangleArea(heights3);
    cout << "Input: ";
    printVector(heights3);
    cout << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 9" << endl
         << endl;

    // Test Case 4: Single bar
    cout << "Test 4: Single bar" << endl;
    vector<int> heights4 = {6};
    int result4 = solution.largestRectangleArea(heights4);
    cout << "Input: ";
    printVector(heights4);
    cout << endl;
    cout << "Output: " << result4 << endl;
    cout << "Expected: 6" << endl
         << endl;

    // Test Case 5: All same heights
    cout << "Test 5: All same heights" << endl;
    vector<int> heights5 = {3, 3, 3, 3};
    int result5 = solution.largestRectangleArea(heights5);
    cout << "Input: ";
    printVector(heights5);
    cout << endl;
    cout << "Output: " << result5 << endl;
    cout << "Expected: 12" << endl
         << endl;

    return 0;
}
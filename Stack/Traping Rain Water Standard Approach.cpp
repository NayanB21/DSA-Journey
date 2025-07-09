/*
Problem: Trapping Rain Water (Standard Two-Pointer Approach)
Description: Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Algorithm: Two-Pointer Approach
- Use two pointers from both ends
- Track left_max and right_max
- Move pointer with smaller maximum
- Water trapped = max_height - current_height

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int water = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0; // otherwise we can use two vectors to store lmax and rmax values for all elements
        while (l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax <= rmax)
            {
                water += lmax - height[l];
                l++;
            }
            else
            {
                water += rmax - height[r];
                r--;
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

    // Test 1: Classic example
    cout << "Test 1: Classic example" << endl;
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result1 = solution.trap(height1);
    cout << "Input: ";
    printVector(height1);
    cout << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 6" << endl
         << endl;

    // Test 2: Simple valley
    cout << "Test 2: Simple valley" << endl;
    vector<int> height2 = {3, 0, 2, 0, 4};
    int result2 = solution.trap(height2);
    cout << "Input: ";
    printVector(height2);
    cout << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 7" << endl
         << endl;

    // Test 3: No water trapped
    cout << "Test 3: No water trapped" << endl;
    vector<int> height3 = {1, 2, 3, 4, 5};
    int result3 = solution.trap(height3);
    cout << "Input: ";
    printVector(height3);
    cout << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 0" << endl
         << endl;

    // Test 4: Single valley
    cout << "Test 4: Single valley" << endl;
    vector<int> height4 = {3, 2, 1, 2, 3};
    int result4 = solution.trap(height4);
    cout << "Input: ";
    printVector(height4);
    cout << endl;
    cout << "Output: " << result4 << endl;
    cout << "Expected: 4" << endl
         << endl;

    // Test 5: Complex pattern
    cout << "Test 5: Complex pattern" << endl;
    vector<int> height5 = {4, 2, 0, 3, 2, 5};
    int result5 = solution.trap(height5);
    cout << "Input: ";
    printVector(height5);
    cout << endl;
    cout << "Output: " << result5 << endl;
    cout << "Expected: 9" << endl
         << endl;

    return 0;
}
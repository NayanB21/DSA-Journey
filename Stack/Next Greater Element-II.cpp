/*
Problem: Next Greater Element II
Description: Given a circular integer array nums, return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order successor in the array,
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation:
- For 1 (index 0): next greater element is 2
- For 2 (index 1): no greater element exists, so -1
- For 1 (index 2): next greater element is 2 (circular search)

Algorithm:
1. Use modulo operation (i%n) to simulate circular behavior without duplicating array
2. Process from 2*n-2 to 0 using a monotonic stack
3. For each element, pop smaller elements from stack
4. The top of stack (if exists) is the next greater element
5. Store indices in stack for efficient comparison

Time Complexity: O(n) where n is the size of the array
Space Complexity: O(n) for the stack and result array
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        // Loop twice through the array using modulo operation (i%n)
        for (int i = 2 * n - 2; i >= 0; i--)
        {
            // Pop elements smaller than or equal to current element
            while (!s.empty() && nums[i % n] >= nums[s.top()])
            {
                s.pop();
            }

            // If stack is empty, no greater element exists
            if (s.empty())
            {
                ans[i % n] = -1;
            }
            else
            {
                ans[i % n] = nums[s.top()];
            }

            // Push current index to stack
            s.push(i % n);
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

    // Test Case 1: Basic circular example
    cout << "Test 1: Basic circular example" << endl;
    vector<int> nums1 = {1, 2, 1};
    vector<int> result1 = solution.nextGreaterElements(nums1);
    cout << "Input: ";
    printVector(nums1);
    cout << endl;
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [2, -1, 2]" << endl
         << endl;

    // Test Case 2: All elements have next greater
    cout << "Test 2: All elements have next greater" << endl;
    vector<int> nums2 = {1, 2, 3, 4, 3};
    vector<int> result2 = solution.nextGreaterElements(nums2);
    cout << "Input: ";
    printVector(nums2);
    cout << endl;
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    cout << "Expected: [2, 3, 4, -1, 4]" << endl
         << endl;

    // Test Case 3: Decreasing array
    cout << "Test 3: Decreasing array" << endl;
    vector<int> nums3 = {5, 4, 3, 2, 1};
    vector<int> result3 = solution.nextGreaterElements(nums3);
    cout << "Input: ";
    printVector(nums3);
    cout << endl;
    cout << "Output: ";
    printVector(result3);
    cout << endl;
    cout << "Expected: [-1, 5, 5, 5, 5]" << endl
         << endl;

    // Test Case 4: Single element
    cout << "Test 4: Single element" << endl;
    vector<int> nums4 = {1};
    vector<int> result4 = solution.nextGreaterElements(nums4);
    cout << "Input: ";
    printVector(nums4);
    cout << endl;
    cout << "Output: ";
    printVector(result4);
    cout << endl;
    cout << "Expected: [-1]" << endl
         << endl;

    // Test Case 5: All same elements
    cout << "Test 5: All same elements" << endl;
    vector<int> nums5 = {3, 3, 3, 3};
    vector<int> result5 = solution.nextGreaterElements(nums5);
    cout << "Input: ";
    printVector(nums5);
    cout << endl;
    cout << "Output: ";
    printVector(result5);
    cout << endl;
    cout << "Expected: [-1, -1, -1, -1]" << endl
         << endl;

    return 0;
}

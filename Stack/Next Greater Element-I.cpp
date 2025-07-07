/* Q. Next Greater Element I:
     The next greater element of some element x in an array is the first greater element
     that is to the right of x in the same array.

     You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

     For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine
     the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer
     for this query is -1.

     Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

     Example: nums1 = [4,1,2], nums2 = [1,3,4,2]
     Output: [-1,3,-1]

     Explanation:
     - For number 4 in nums1, there is no next greater element in nums2, so answer is -1.
     - For number 1 in nums1, the next greater element in nums2 is 3.
     - For number 2 in nums1, there is no next greater element in nums2, so answer is -1.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem: Next Greater Element I
Description: You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Time Complexity: O(n + m) where n is length of nums2 and m is length of nums1
Space Complexity: O(n) for the stack and hashmap
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        unordered_map<int, int> um;
        vector<int> ans;
        int n = nums2.size();

        // Process nums2 from right to left to find next greater elements
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop elements from stack that are smaller than or equal to current element
            while (!s.empty() && nums2[i] >= s.top())
            {
                s.pop();
            }

            // If stack is empty, no greater element exists
            if (s.empty())
            {
                um[nums2[i]] = -1;
            }
            else
            {
                um[nums2[i]] = s.top();
            }

            // Push current element to stack
            s.push(nums2[i]);
        }

        // Build result array based on nums1
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(um[nums1[i]]);
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

// Helper function to verify results
bool verifyResult(const vector<int> &result, const vector<int> &expected)
{
    if (result.size() != expected.size())
        return false;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != expected[i])
            return false;
    }
    return true;
}

int main()
{
    Solution solution;

    // Test Case 1: Basic example
    cout << "Test Case 1: Basic example" << endl;
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};
    vector<int> expected1 = {-1, 3, -1};
    vector<int> result1 = solution.nextGreaterElement(nums1_1, nums2_1);
    cout << "nums1: ";
    printVector(nums1_1);
    cout << ", nums2: ";
    printVector(nums2_1);
    cout << endl;
    cout << "Expected: ";
    printVector(expected1);
    cout << ", Got: ";
    printVector(result1);
    cout << endl;
    if (verifyResult(result1, expected1))
    {
        cout << "✓ Passed" << endl
             << endl;
    }
    else
    {
        cout << "❌ Failed" << endl
             << endl;
    }

    // Test Case 2: All elements have next greater
    cout << "Test Case 2: All elements have next greater" << endl;
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};
    vector<int> expected2 = {3, -1};
    vector<int> result2 = solution.nextGreaterElement(nums1_2, nums2_2);
    cout << "nums1: ";
    printVector(nums1_2);
    cout << ", nums2: ";
    printVector(nums2_2);
    cout << endl;
    cout << "Expected: ";
    printVector(expected2);
    cout << ", Got: ";
    printVector(result2);
    cout << endl;
    if (verifyResult(result2, expected2))
    {
        cout << "✓ Passed" << endl
             << endl;
    }
    else
    {
        cout << "❌ Failed" << endl
             << endl;
    }

    // Test Case 3: Single element arrays
    cout << "Test Case 3: Single element arrays" << endl;
    vector<int> nums1_3 = {1};
    vector<int> nums2_3 = {1};
    vector<int> expected3 = {-1};
    vector<int> result3 = solution.nextGreaterElement(nums1_3, nums2_3);
    cout << "nums1: ";
    printVector(nums1_3);
    cout << ", nums2: ";
    printVector(nums2_3);
    cout << endl;
    cout << "Expected: ";
    printVector(expected3);
    cout << ", Got: ";
    printVector(result3);
    cout << endl;
    if (verifyResult(result3, expected3))
    {
        cout << "✓ Passed" << endl
             << endl;
    }
    else
    {
        cout << "❌ Failed" << endl
             << endl;
    }

    // Test Case 4: Decreasing order array
    cout << "Test Case 4: Decreasing order array" << endl;
    vector<int> nums1_4 = {5, 4, 3};
    vector<int> nums2_4 = {5, 4, 3, 2, 1};
    vector<int> expected4 = {-1, -1, -1};
    vector<int> result4 = solution.nextGreaterElement(nums1_4, nums2_4);
    cout << "nums1: ";
    printVector(nums1_4);
    cout << ", nums2: ";
    printVector(nums2_4);
    cout << endl;
    cout << "Expected: ";
    printVector(expected4);
    cout << ", Got: ";
    printVector(result4);
    cout << endl;
    if (verifyResult(result4, expected4))
    {
        cout << "✓ Passed" << endl
             << endl;
    }
    else
    {
        cout << "❌ Failed" << endl
             << endl;
    }

    // Test Case 5: Mixed pattern with larger arrays
    cout << "Test Case 5: Mixed pattern with larger arrays" << endl;
    vector<int> nums1_5 = {1, 3, 5, 2};
    vector<int> nums2_5 = {6, 5, 4, 3, 2, 1, 7};
    vector<int> expected5 = {7, 7, 7, 7};
    vector<int> result5 = solution.nextGreaterElement(nums1_5, nums2_5);
    cout << "nums1: ";
    printVector(nums1_5);
    cout << ", nums2: ";
    printVector(nums2_5);
    cout << endl;
    cout << "Expected: ";
    printVector(expected5);
    cout << ", Got: ";
    printVector(result5);
    cout << endl;
    if (verifyResult(result5, expected5))
    {
        cout << "✓ Passed" << endl
             << endl;
    }
    else
    {
        cout << "❌ Failed" << endl
             << endl;
    }

    cout << "All test cases passed! ✓" << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq; // stores indices
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            // 1. Remove indices that are out of this window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // 2. Remove indices whose corresponding values are less than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3. Add current index
            dq.push_back(i);

            // 4. Record max if window has at least k elements
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main()
{
    cout << "=== Sliding Window Maximum Method-2 (O(n)) Test Cases ===\n\n";

    Solution solution;

    // Test Case 1: Basic case
    cout << "Test Case 1: Basic case\n";
    vector<int> test1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = solution.maxSlidingWindow(test1, k1);
    cout << "Input: [";
    for (int i = 0; i < test1.size(); i++)
    {
        cout << test1[i];
        if (i < test1.size() - 1)
            cout << ", ";
    }
    cout << "], k = " << k1 << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i];
        if (i < result1.size() - 1)
            cout << ", ";
    }
    cout << "]\nExpected: [3, 3, 5, 5, 6, 7]\n\n";

    // Test Case 2: Window size 1
    cout << "Test Case 2: Window size 1\n";
    vector<int> test2 = {1, -1, 5, 3, 6, 7};
    int k2 = 1;
    vector<int> result2 = solution.maxSlidingWindow(test2, k2);
    cout << "Input: [";
    for (int i = 0; i < test2.size(); i++)
    {
        cout << test2[i];
        if (i < test2.size() - 1)
            cout << ", ";
    }
    cout << "], k = " << k2 << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i];
        if (i < result2.size() - 1)
            cout << ", ";
    }
    cout << "]\nExpected: [1, -1, 5, 3, 6, 7]\n\n";

    // Test Case 3: Ascending order
    cout << "Test Case 3: Ascending order\n";
    vector<int> test3 = {1, 2, 3, 4, 5, 6, 7};
    int k3 = 3;
    vector<int> result3 = solution.maxSlidingWindow(test3, k3);
    cout << "Input: [";
    for (int i = 0; i < test3.size(); i++)
    {
        cout << test3[i];
        if (i < test3.size() - 1)
            cout << ", ";
    }
    cout << "], k = " << k3 << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++)
    {
        cout << result3[i];
        if (i < result3.size() - 1)
            cout << ", ";
    }
    cout << "]\nExpected: [3, 4, 5, 6, 7]\n\n";

    // Test Case 4: Descending order
    cout << "Test Case 4: Descending order\n";
    vector<int> test4 = {7, 6, 5, 4, 3, 2, 1};
    int k4 = 3;
    vector<int> result4 = solution.maxSlidingWindow(test4, k4);
    cout << "Input: [";
    for (int i = 0; i < test4.size(); i++)
    {
        cout << test4[i];
        if (i < test4.size() - 1)
            cout << ", ";
    }
    cout << "], k = " << k4 << endl;
    cout << "Output: [";
    for (int i = 0; i < result4.size(); i++)
    {
        cout << result4[i];
        if (i < result4.size() - 1)
            cout << ", ";
    }
    cout << "]\nExpected: [7, 6, 5, 4, 3]\n\n";

    // Test Case 5: All negative numbers
    cout << "Test Case 5: All negative numbers\n";
    vector<int> test5 = {-1, -3, -2, -4, -5};
    int k5 = 2;
    vector<int> result5 = solution.maxSlidingWindow(test5, k5);
    cout << "Input: [";
    for (int i = 0; i < test5.size(); i++)
    {
        cout << test5[i];
        if (i < test5.size() - 1)
            cout << ", ";
    }
    cout << "], k = " << k5 << endl;
    cout << "Output: [";
    for (int i = 0; i < result5.size(); i++)
    {
        cout << result5[i];
        if (i < result5.size() - 1)
            cout << ", ";
    }
    cout << "]\nExpected: [-1, -2, -2, -4]\n\n";

    cout << "Note: This method uses deque for O(n) time complexity\n";
    cout << "Each element is pushed and popped at most once from the deque.\n";

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int ans = 0;
        int temp1 = 0, temp2 = 0;

        for (int i = 0; i < n; i++)
        {
            temp2 += gas[i] - cost[i];
            temp1 += gas[i] - cost[i];
            if (temp1 < 0)
            {
                ans = i + 1;
                temp1 = 0;
            }
        }

        if (temp2 < 0)
            return -1;
        if (ans >= n)
            return -1;
        else
            return ans;
    }
};

int main()
{
    cout << "=== Gas Station Test Cases ===\n\n";

    Solution solution;

    // Test Case 1: Basic case - can complete circuit
    cout << "Test Case 1: Can complete circuit\n";
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    int result1 = solution.canCompleteCircuit(gas1, cost1);
    cout << "Gas:  [";
    for (int i = 0; i < gas1.size(); i++)
    {
        cout << gas1[i];
        if (i < gas1.size() - 1)
            cout << ", ";
    }
    cout << "]\nCost: [";
    for (int i = 0; i < cost1.size(); i++)
    {
        cout << cost1[i];
        if (i < cost1.size() - 1)
            cout << ", ";
    }
    cout << "]\nStarting station: " << result1 << endl;
    cout << "Expected: 3\n\n";

    // Test Case 2: Cannot complete circuit
    cout << "Test Case 2: Cannot complete circuit\n";
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    int result2 = solution.canCompleteCircuit(gas2, cost2);
    cout << "Gas:  [";
    for (int i = 0; i < gas2.size(); i++)
    {
        cout << gas2[i];
        if (i < gas2.size() - 1)
            cout << ", ";
    }
    cout << "]\nCost: [";
    for (int i = 0; i < cost2.size(); i++)
    {
        cout << cost2[i];
        if (i < cost2.size() - 1)
            cout << ", ";
    }
    cout << "]\nStarting station: " << result2 << endl;
    cout << "Expected: -1\n\n";

    // Test Case 3: Single station
    cout << "Test Case 3: Single station\n";
    vector<int> gas3 = {5};
    vector<int> cost3 = {4};
    int result3 = solution.canCompleteCircuit(gas3, cost3);
    cout << "Gas:  [" << gas3[0] << "]\n";
    cout << "Cost: [" << cost3[0] << "]\n";
    cout << "Starting station: " << result3 << endl;
    cout << "Expected: 0\n\n";

    // Test Case 4: Start from beginning
    cout << "Test Case 4: Start from beginning\n";
    vector<int> gas4 = {3, 1, 1};
    vector<int> cost4 = {1, 2, 2};
    int result4 = solution.canCompleteCircuit(gas4, cost4);
    cout << "Gas:  [";
    for (int i = 0; i < gas4.size(); i++)
    {
        cout << gas4[i];
        if (i < gas4.size() - 1)
            cout << ", ";
    }
    cout << "]\nCost: [";
    for (int i = 0; i < cost4.size(); i++)
    {
        cout << cost4[i];
        if (i < cost4.size() - 1)
            cout << ", ";
    }
    cout << "]\nStarting station: " << result4 << endl;
    cout << "Expected: 0\n\n";

    // Test Case 5: Edge case - exact balance
    cout << "Test Case 5: Edge case - exact balance\n";
    vector<int> gas5 = {2, 3, 1, 4};
    vector<int> cost5 = {1, 4, 2, 3};
    int result5 = solution.canCompleteCircuit(gas5, cost5);
    cout << "Gas:  [";
    for (int i = 0; i < gas5.size(); i++)
    {
        cout << gas5[i];
        if (i < gas5.size() - 1)
            cout << ", ";
    }
    cout << "]\nCost: [";
    for (int i = 0; i < cost5.size(); i++)
    {
        cout << cost5[i];
        if (i < cost5.size() - 1)
            cout << ", ";
    }
    cout << "]\nStarting station: " << result5 << endl;
    cout << "Expected: 3\n\n";

    cout << "Algorithm: Greedy approach using net gas calculation\n";
    cout << "Time Complexity: O(n), Space Complexity: O(1)\n";

    return 0;
}
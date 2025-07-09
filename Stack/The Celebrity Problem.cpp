#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
THE CELEBRITY PROBLEM

Problem Statement:
A celebrity is a person who is known by everyone but doesn't know anyone at a party.
Given a square matrix M[][] where M[i][j] = 1 means person i knows person j,
and M[i][j] = 0 means person i doesn't know person j.

Find the celebrity in the party. If there is no celebrity, return -1.

Celebrity Properties:
1. Celebrity knows nobody (all entries in celebrity's row should be 0)
2. Everyone knows the celebrity (all entries in celebrity's column should be 1, except diagonal)
3. There can be at most one celebrity

Algorithm Approach:
1. Use a stack to eliminate non-celebrity candidates
2. Push all person indices (0 to n-1) into stack
3. While stack has more than 1 element:
   - Pop two persons i and j
   - If i knows j, then i cannot be celebrity (push j back)
   - If i doesn't know j, then j cannot be celebrity (push i back)
4. The remaining person is potential celebrity
5. Verify if this person satisfies celebrity conditions

Time Complexity: O(n)
Space Complexity: O(n)
*/

int getCelebrity(vector<vector<int>> &arr)
{
    int n = arr.size();
    stack<int> s;

    // Push all persons into stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Eliminate non-celebrity candidates
    while (s.size() != 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        // If i knows j, i cannot be celebrity
        if (arr[i][j] == 1)
        {
            s.push(j);
        }
        // If i doesn't know j, j cannot be celebrity
        else
        {
            s.push(i);
        }
    }

    int celeb = s.top();

    // Verify if the potential celebrity satisfies all conditions
    for (int k = 0; k < n; k++)
    {
        // Celebrity should not know anyone (row check) AND everyone should know celebrity (column check)
        if (k != celeb && (arr[celeb][k] == 1 || arr[k][celeb] == 0))
        {
            return -1;
        }
    }

    return celeb;
}

int main()
{
    cout << "=== THE CELEBRITY PROBLEM - TEST CASES ===" << endl;

    // Test Case 1: Celebrity exists at index 1
    cout << "\nTest Case 1: Celebrity at index 1" << endl;
    vector<vector<int>> test1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    int result1 = getCelebrity(test1);
    cout << "Matrix: [[0,1,0], [0,0,0], [0,1,0]]" << endl;
    cout << "Expected: 1, Got: " << result1 << endl;
    cout << "Result: " << (result1 == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 2: No celebrity exists
    cout << "\nTest Case 2: No celebrity" << endl;
    vector<vector<int>> test2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    int result2 = getCelebrity(test2);
    cout << "Matrix: [[0,1,0], [1,0,1], [0,1,0]]" << endl;
    cout << "Expected: -1, Got: " << result2 << endl;
    cout << "Result: " << (result2 == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Celebrity at index 0
    cout << "\nTest Case 3: Celebrity at index 0" << endl;
    vector<vector<int>> test3 = {
        {0, 0, 0},
        {1, 0, 1},
        {1, 0, 0}};
    int result3 = getCelebrity(test3);
    cout << "Matrix: [[0,0,0], [1,0,1], [1,0,0]]" << endl;
    cout << "Expected: 0, Got: " << result3 << endl;
    cout << "Result: " << (result3 == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: 4x4 matrix with celebrity at index 2
    cout << "\nTest Case 4: 4x4 matrix, celebrity at index 2" << endl;
    vector<vector<int>> test4 = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}};
    int result4 = getCelebrity(test4);
    cout << "Matrix: 4x4 with celebrity at index 2" << endl;
    cout << "Expected: 2, Got: " << result4 << endl;
    cout << "Result: " << (result4 == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single person (always celebrity)
    cout << "\nTest Case 5: Single person matrix" << endl;
    vector<vector<int>> test5 = {
        {0}};
    int result5 = getCelebrity(test5);
    cout << "Matrix: [[0]]" << endl;
    cout << "Expected: 0, Got: " << result5 << endl;
    cout << "Result: " << (result5 == 0 ? "PASS" : "FAIL") << endl;

    cout << "\n=== ALL TEST CASES COMPLETED ===" << endl;

    return 0;
}
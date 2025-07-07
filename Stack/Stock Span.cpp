/* Q. The Stock Span Problem:
     Given an array of stock prices, find the span of stock's price for all the days.
     The span of the stock's price on a given day is defined as the maximum number of consecutive days
     (starting from that day and going backwards) for which the price of the stock was less than or equal
     to the price on that day.

     Example: prices = [100, 80, 60, 70, 60, 75, 85]
     Output: [1, 1, 1, 2, 1, 4, 6]

     Explanation:
     - Day 0: 100, span = 1 (only current day)
     - Day 1: 80, span = 1 (80 < 100)
     - Day 2: 60, span = 1 (60 < 80)
     - Day 3: 70, span = 2 (70 >= 60, 70 < 80)
     - Day 4: 60, span = 1 (60 < 70)
     - Day 5: 75, span = 4 (75 >= 60, 75 >= 70, 75 >= 60, 75 < 80)
     - Day 6: 85, span = 6 (85 >= all previous except 100)
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> stockSpan(vector<int> &vec)
{
    int n = vec.size();
    vector<int> ans;
    stack<int> st;
    st.push(0);
    ans.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (vec[i] < vec[st.top()])
        {
            ans.push_back(1);
            st.push(i);
        }
        else
        {
            while (!st.empty() && vec[i] >= vec[st.top()])
                st.pop();

            if (st.empty())
            {
                ans.push_back(i + 1);
            }
            else
            {
                ans.push_back(i - st.top());
            }
            st.push(i);
        }
    }
    return ans;
}

// Helper function to print vector
void printVector(const vector<int> &vec, const string &label)
{
    cout << label << ": [";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

// Helper function to verify result
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

    // Test case 1: Standard example [100,80,60,70,60,75,85]
    cout << "Test 1 - Standard stock span:" << endl;
    vector<int> prices1{100, 80, 60, 70, 60, 75, 85};
    vector<int> expected1{1, 1, 1, 2, 1, 4, 6};

    printVector(prices1, "Prices");
    vector<int> result1 = stockSpan(prices1);
    printVector(result1, "Span");
    printVector(expected1, "Expected");
    cout << "Result matches: " << (verifyResult(result1, expected1) ? "Yes" : "No") << endl
         << endl;

    // Test case 2: Increasing sequence [10,20,30,40,50]
    cout << "Test 2 - Increasing sequence:" << endl;
    vector<int> prices2{10, 20, 30, 40, 50};
    vector<int> expected2{1, 2, 3, 4, 5};

    printVector(prices2, "Prices");
    vector<int> result2 = stockSpan(prices2);
    printVector(result2, "Span");
    printVector(expected2, "Expected");
    cout << "Result matches: " << (verifyResult(result2, expected2) ? "Yes" : "No") << endl
         << endl;

    // Test case 3: Decreasing sequence [50,40,30,20,10]
    cout << "Test 3 - Decreasing sequence:" << endl;
    vector<int> prices3{50, 40, 30, 20, 10};
    vector<int> expected3{1, 1, 1, 1, 1};

    printVector(prices3, "Prices");
    vector<int> result3 = stockSpan(prices3);
    printVector(result3, "Span");
    printVector(expected3, "Expected");
    cout << "Result matches: " << (verifyResult(result3, expected3) ? "Yes" : "No") << endl
         << endl;

    // Test case 4: Single element [42]
    cout << "Test 4 - Single element:" << endl;
    vector<int> prices4{42};
    vector<int> expected4{1};

    printVector(prices4, "Prices");
    vector<int> result4 = stockSpan(prices4);
    printVector(result4, "Span");
    printVector(expected4, "Expected");
    cout << "Result matches: " << (verifyResult(result4, expected4) ? "Yes" : "No") << endl
         << endl;

    // Test case 5: Mixed pattern [31,41,48,59,79]
    cout << "Test 5 - Mixed pattern:" << endl;
    vector<int> prices5{31, 41, 48, 59, 79};
    vector<int> expected5{1, 2, 3, 4, 5};

    printVector(prices5, "Prices");
    vector<int> result5 = stockSpan(prices5);
    printVector(result5, "Span");
    printVector(expected5, "Expected");
    cout << "Result matches: " << (verifyResult(result5, expected5) ? "Yes" : "No") << endl;

    return 0;
}
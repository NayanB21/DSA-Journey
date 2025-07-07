/* Q. Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
     determine if the input string is valid.

     An input string is valid if:
     1. Open brackets must be closed by the same type of brackets.
     2. Open brackets must be closed in the correct order.
     3. Every close bracket has a corresponding open bracket of the same type.

     Example: "()" is valid, "()[]{}" is valid, "(]" is invalid
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int len = s.length();

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.size() == 0)
                    return false;

                if (st.top() == '(' && s[i] == ')' ||
                    st.top() == '{' && s[i] == '}' ||
                    st.top() == '[' && s[i] == ']')
                    st.pop();

                else
                    return false;
            }
        }

        return st.size() == 0;
    }
};

int main()
{
    Solution solution;

    // Test case 1: Valid simple parentheses "()"
    cout << "Test 1 - Valid simple parentheses:" << endl;
    string s1 = "()";
    cout << "Input: \"" << s1 << "\"" << endl;
    bool result1 = solution.isValid(s1);
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: true" << endl
         << endl;

    // Test case 2: Valid mixed parentheses "()[]{}"
    cout << "Test 2 - Valid mixed parentheses:" << endl;
    string s2 = "()[]{}";
    cout << "Input: \"" << s2 << "\"" << endl;
    bool result2 = solution.isValid(s2);
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: true" << endl
         << endl;

    // Test case 3: Invalid mismatched "(]"
    cout << "Test 3 - Invalid mismatched:" << endl;
    string s3 = "(]";
    cout << "Input: \"" << s3 << "\"" << endl;
    bool result3 = solution.isValid(s3);
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: false" << endl
         << endl;

    // Test case 4: Invalid unmatched "([)]"
    cout << "Test 4 - Invalid wrong order:" << endl;
    string s4 = "([)]";
    cout << "Input: \"" << s4 << "\"" << endl;
    bool result4 = solution.isValid(s4);
    cout << "Output: " << (result4 ? "true" : "false") << endl;
    cout << "Expected: false" << endl
         << endl;

    
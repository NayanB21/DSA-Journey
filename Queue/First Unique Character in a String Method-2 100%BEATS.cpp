#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < n; i++)
        {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    cout << "=== First Unique Character Test Cases ===\n\n";

    Solution solution;

    // Test Case 1: Basic case with unique character
    cout << "Test Case 1: Basic case\n";
    string test1 = "leetcode";
    int result1 = solution.firstUniqChar(test1);
    cout << "Input: \"" << test1 << "\"\n";
    cout << "First unique character index: " << result1 << endl;
    if (result1 != -1)
        cout << "Character: '" << test1[result1] << "'\n";
    cout << "Expected: 0 (character 'l')\n\n";

    // Test Case 2: No unique characters
    cout << "Test Case 2: No unique characters\n";
    string test2 = "aabbcc";
    int result2 = solution.firstUniqChar(test2);
    cout << "Input: \"" << test2 << "\"\n";
    cout << "First unique character index: " << result2 << endl;
    cout << "Expected: -1 (no unique characters)\n\n";

    // Test Case 3: Single character
    cout << "Test Case 3: Single character\n";
    string test3 = "a";
    int result3 = solution.firstUniqChar(test3);
    cout << "Input: \"" << test3 << "\"\n";
    cout << "First unique character index: " << result3 << endl;
    if (result3 != -1)
        cout << "Character: '" << test3[result3] << "'\n";
    cout << "Expected: 0 (character 'a')\n\n";

    // Test Case 4: Unique character at the end
    cout << "Test Case 4: Unique character at the end\n";
    string test4 = "aabbccz";
    int result4 = solution.firstUniqChar(test4);
    cout << "Input: \"" << test4 << "\"\n";
    cout << "First unique character index: " << result4 << endl;
    if (result4 != -1)
        cout << "Character: '" << test4[result4] << "'\n";
    cout << "Expected: 6 (character 'z')\n\n";

    // Test Case 5: Multiple unique characters
    cout << "Test Case 5: Multiple unique characters\n";
    string test5 = "abcdef";
    int result5 = solution.firstUniqChar(test5);
    cout << "Input: \"" << test5 << "\"\n";
    cout << "First unique character index: " << result5 << endl;
    if (result5 != -1)
        cout << "Character: '" << test5[result5] << "'\n";
    cout << "Expected: 0 (character 'a')\n\n";

    // Additional Test Case 6: Complex pattern
    cout << "Test Case 6: Complex pattern\n";
    string test6 = "loveleetcode";
    int result6 = solution.firstUniqChar(test6);
    cout << "Input: \"" << test6 << "\"\n";
    cout << "First unique character index: " << result6 << endl;
    if (result6 != -1)
        cout << "Character: '" << test6[result6] << "'\n";
    cout << "Expected: 2 (character 'v')\n";

    return 0;
}
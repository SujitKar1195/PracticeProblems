/*

Problem: Longest Prefix Suffix

Given a string s, find the length of the longest prefix, which is also a suffix. The prefix and suffix should not overlap.

Examples:

Input : S = aabcdaabc
Output : 4
Explanation: The string “aabc” is the longest prefix which is also suffix.

Input : S = abcab
Output : 2

Input : S = aaaa
Output : 2

*/

#include <bits/stdc++.h>
using namespace std;

void findLps(vector<int> &lps, string &s)
{
    int preIndex = 0;
    int sufIndex = 1;

    while (sufIndex < s.size())
    {
        if (s[preIndex] == s[sufIndex])
        {
            lps[sufIndex] = preIndex + 1;
            preIndex++;
            sufIndex++;
        }
        else
        {
            if (preIndex == 0)
            {
                lps[sufIndex] = 0;
                sufIndex++;
            }
            else
            {
                preIndex = lps[preIndex - 1];
            }
        }
    }
}

int main()
{
    int t;
    cout << "No of testcases: ";
    cin >> t;
    while (t--)
    {
        string s;
        cout << "Enter string: ";
        cin >> s;

        vector<int> lps(s.size(), 0);
        findLps(lps, s);
        int length = lps[lps.size() - 1];
        cout << "Longest prefix suffix length: " << length << endl;

        string prefix = "";

        for (int i = 0; i < length; i++)
        {
            prefix += s[i];
        }

        cout << "And the string is: " << prefix << endl;
        cout << "Lps table: " << endl;
        for (int &i : lps)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
You are given string str. You need to remove the consecutive duplicates from the given string using a Stack.

Input:
aaaaaabaabccccccc

Output:
ababc

Explanation:
The order is in the following way 6->a, 1->b, 2->a, 1->b, 7->c.
So, only one element from each group will remain and rest all are removed.
Therefore, final string will be:- ababc.

Input:
abbccbcd

Output:
abcbcd
*/

#include <bits/stdc++.h>
using namespace std;

void remove(string str)
{
    stack<char> s;
    s.push(str[0]);
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != s.top())
        {
            s.push(str[i]);
        }
    }

    string res = "";
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    cout << "After remving consecutive duplicative =>: " << res << endl;
}

int main()
{
    string s;
    cout << "Enter string : ";
    cin >> s;
    remove(s);

    return 0;
}
/*
Problem:

Given an integer s and d, The task is to find the largest number with given digit sum s and the number of digits d.

Input: s = 9, d = 2
Output: 90

Input: s = 20, d = 3
Output: 992

*/

#include <bits/stdc++.h>
using namespace std;

string largestPossibleDigit(int s, int d)
{
    if (s < 0 || d < 0)
        return "-1";
    if (s == 0 && d > 1)
        return "-1";
    string ans = "";

    for (int i = 0; i < d; i++)
    {
        if (s >= 9)
        {
            ans += "9";
            s -= 9;
        }
        else
        {
            char c = s + '0';
            ans += c;
            s = 0;
        }
    }

    if (s > 0)
        return "-1";
    return ans;
}

int main()
{
    int s, d;
    cout << "Enter sum of digits: ";
    cin >> s;
    cout << "Enter No of digits: ";
    cin >> d;

    string ans = largestPossibleDigit(s, d);

    if (ans == "-1")
    {
        cout << "No is not possible" << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}
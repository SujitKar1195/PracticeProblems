/*
Problem: Minimum number of coins.

Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required.

Input: N = 43
Output: 20 20 2 1

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N)
{
    vector<int> ans;
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    for (int i = 9; i >= 0; i--)
    {
        while (N >= a[i])
        {
            N -= a[i];
            ans.push_back(a[i]);
        }
    }

    return ans;
}

int main()
{
    int amount;
    cout << "Amount: ";
    cin >> amount;
    vector<int> ans = minPartition(amount);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
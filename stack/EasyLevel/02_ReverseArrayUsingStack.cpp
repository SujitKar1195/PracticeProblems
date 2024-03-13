/*
You are given an array arr[] of size N, the task is to reverse the array elements in-place by using a stack.

Example 1:

Input: N = 5, arr[] = {1, 2, 3, 4, 5}
Output: 5 4 3 2 1
*/

#include <bits/stdc++.h>
using namespace std;

stack<int> myPush(vector<int> s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
        st.push(s[i]);
    return st;
}

void rev(stack<int> &s, vector<int> &v)
{
    int size = v.size();
    for(int i=0;i<size;i++)
    {
        v[i] = s.top();
        s.pop();
    }

}

int main()
{
    int t;
    cout << "Enter test case: ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter size : ";
        cin >> n;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cout << "Enter element: ";
            cin>>x;
            v.push_back(x);
        }

        stack<int> s = myPush(v);

        rev(s, v);

        // reverse(v.begin(), v.end());
        cout<<"After reversing : ";
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
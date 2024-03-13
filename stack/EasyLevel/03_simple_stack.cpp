/*
Difficulty Easy
Company Tag:
Stack(Easy)
You are given an array arr of size N. You need to push the elements of the array into a stack and then print them while popping.

Input:
1
5
1 2 3 4 5
Output:
1
5
5 4 3 2 1
Input:
 7
1 6 43 1 2 0 5
Output:
5 0 2 1 43 6 1

*/

#include <bits/stdc++.h>
using namespace std;

stack<int> myPush(vector<int> v)
{
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    return s;
}

void myPop(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int t;
    cout << "Test Case: ";
    cin >> t;
    while (t--)
    {

        int n;
        cout << "Enter the size of the array : ";
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {

            int x;
            cout << "Enter element\n";
            cin >> x;
            v.push_back(x);
        }
        stack<int> s = myPush(v);

        cout << "Value of the stack is now: ";
        myPop(s);
    }

    return 0;
}
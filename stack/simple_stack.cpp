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
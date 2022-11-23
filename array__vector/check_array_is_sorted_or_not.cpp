#include <bits/stdc++.h>
using namespace std;

int isSorted(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the size : ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (isSorted(v))
    {
        cout << "Yes! sorted\n";
    }
    else
    {
        cout << "Not sorted\n";
    }

    return 0;
}
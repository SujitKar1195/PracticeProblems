#include <bits/stdc++.h>
using namespace std;

void maximumSum(vector<int> &v, int n)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }

    cout << maxi << endl;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter data: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    maximumSum(v, n);

    return 0;
}
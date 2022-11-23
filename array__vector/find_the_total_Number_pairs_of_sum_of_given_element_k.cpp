// TimeComplexity=>O(n^2);

#include <bits/stdc++.h>
using namespace std;

void ans(vector<int> v, int k)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (v[i] + v[j] == k)
            {
                count++;
                cout << "Pair indices are : " << i << " & " << j << endl;
            }
    cout << "Total pair : " << count << endl;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cout << "Enter k value : ";
    cin >> k;

    ans(v, k);

    return 0;
}
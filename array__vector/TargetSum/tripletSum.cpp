#include <bits/stdc++.h>
using namespace std;

void ans(vector<int> v, int k)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
                if (v[i] + v[j] + v[k] == k)
                {
                    count++;
                    cout << "Triplets are : " << i << " " << j << " " << k << endl;
                }
        }
    }
    cout << count << endl;
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
    cout << "TargetSum value : ";
    cin >> k;

    ans(v, k);

    return 0;
}
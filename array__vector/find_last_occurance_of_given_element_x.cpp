#include <bits/stdc++.h>
using namespace std;

void ans(vector<int> v, int x, int n)
{
    int index = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == x)
        {
            index = i;
            break;
        }
    }

    cout << "Index of the last occurance of element " << x << " : " << index << endl;
}

int main()
{
    int n;
    cout << "size : " << endl;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int element;
        cout << "number : ";
        cin >> v[i];
        // v.push_back(element);
    }

    int x;
    cout << "\nBaata konsa number hai woh : \n";
    cin >> x;

    ans(v, x, n);

    return 0;
}
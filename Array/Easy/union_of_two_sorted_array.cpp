#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> Union(int a[], int n, int b[], int m)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            if (v.size() == 0 || v.back() != a[i])
            {
                v.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (v.size() == 0 || v.back() != b[j])
            {
                v.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (v.size() == 0 || v.back() != a[i])
        {
            v.push_back(a[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (v.size() == 0 || v.back() != b[j])
        {
            v.push_back(b[j]);
        }
        j++;
    }

    return v;
}

int main()
{
    int n;
    cout << "Enter 1st array size: ";
    cin >> n;

    // creation of 1st array
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cout << "Enter 2nd array size: ";
    cin >> m;

    // creation of 2nd array
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> v = Union(a, n, b, m);
    print(v);

    return 0;
}
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

vector<int> Intersection(int a[], int n, int b[], int m)
{
    vector<int> intersection;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            if (intersection.size() == 0 || intersection.back() != a[i])
            {
                intersection.push_back(a[i]);
            }
            i++, j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }

    return intersection;
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

    vector<int> v = Intersection(a, n, b, m);
    print(v);

    return 0;
}
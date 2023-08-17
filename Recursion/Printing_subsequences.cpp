#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void subsequence(int i, int n, int a[], vector<int> &v)
{
    if (i >= n)
    {
        print(v);
        return;
    }

    v.push_back(a[i]);
    subsequence(i + 1, n, a, v);
    v.pop_back();
    subsequence(i + 1, n, a, v);
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> v;

    subsequence(0, n, a, v);

    return 0;
}
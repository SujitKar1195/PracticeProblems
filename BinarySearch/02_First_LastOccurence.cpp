#include <iostream>
#include <utility>
using namespace std;

pair<int, int> first_last_occurence(int a[], int s, int e, int key)
{
    int first = -1, last = -1;
    int start = s;
    int end = e;

    // first occurence
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] == key)
        {
            first = mid;
            end = mid - 1;
        }
        else if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    // last occurence
    start = s, end = e;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] == key)
        {
            last = mid;
            start = mid + 1;
        }
        else if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    pair<int, int> p(first, last);
    return p;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // array creation
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Enter key;
    int key;
    cout << "Enter Key: ";
    cin >> key;

    pair<int, int> p = first_last_occurence(a, 0, n - 1, key);
    cout << p.first << " " << p.second << endl;
    return 0;
}
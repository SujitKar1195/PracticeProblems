#include <iostream>
using namespace std;

int binary_search(int a[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    // If the element is not found
    return -1;
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

    int index = binary_search(a, 0, n - 1, key);
    if (index != -1)
    {
        cout << key << " is found at position: " << index << endl;
    }
    else
    {
        cout << key << " is not found" << endl;
    }

    return 0;
}
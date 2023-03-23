/*
    Author: Sujit Kar
    Date: 17/03/2023
    Topic: First negative integer in every window of size k(brute force approach)
    for optimize solution check SlidingWindow section
    Time Complexity: O(n^2)
    Space Complexity: O()
    I/P:
        size: 5
        arr: -8 2 - 6 1 0
        window_size: 3
    O/P:
        -8 -6 -6
*/

#include <iostream>
using namespace std;

void result(int *a, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < i + k; j++)
        {
            if (a[j] < 0)
            {
                cout << a[j] << " ";
                break;
            }

        }
    }

    cout << endl;
}

int main()
{
    int t;
    cout << "Enter test cases : ";
    cin >> t;

    while (t--)
    {
        int n;
        cout << "Array Size: ";
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int k;
        cout << "Enter window(subarray) size: ";
        cin >> k;
        result(a, n, k);
    }

    return 0;
}
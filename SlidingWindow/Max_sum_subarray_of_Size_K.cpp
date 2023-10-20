/*
    Author: Sujit Kar
    Date: 17/03/2023
    Topic: Maximum sum subarray of size k
    Time Complexity: O(n)
    Space Complexity: O()
    I/P:
        size : 7
        arr: 2 5 1 8 2 9 1
    O/P: 19

*/
#include <iostream>
#include <climits>
using namespace std;

void calculate(int *a, int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int m = INT_MIN;
    while (j < n)
    {
        sum += a[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {

            m = max(m, sum);
            sum = sum - a[i++];
            j++;
        }
    }

    cout << m << endl;
}

int main()
{
    int t;
    cout << "Enter test cases : ";
    cin >> t;

    while (t--)
    {
        int n;
        cout << "Array size: ";
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int k;
        cout << "Enter Subarray(window) size : ";
        cin >> k;
        calculate(a, n, k);
    }

    return 0;
}
#include <iostream>
using namespace std;

void reverse(int a[], int i, int n)
{
    if (i > ((n / 2) - 1)) // reversing elements till half of the array
        return;

    int t = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = t; // swap elements
    reverse(a, ++i, n);
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // creating an array

    int a[n];

    // Taking input
    for (int i = 0; i < n; i++)
        cin >> a[i];

    reverse(a, 0, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
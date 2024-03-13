#include <iostream>
using namespace std;

void movesZeroesToTheEnd(int a[], int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[i] == 0 && a[j] != 0 && j < n)
        {
            swap(a[i], a[j]);
            i++, j++;
        }
        else if (a[i] == 0 && a[j] == 0)
        {
            j++;
        }
        else
            i++, j++;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // creation of array
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    movesZeroesToTheEnd(a, n);

    // Printing Array
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
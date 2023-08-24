#include <iostream>
#include <vector>
using namespace std;

void rotateBy_D_places(int a[], int n, int d)
{
    vector<int> temp; // temporary array
    for (int i = 0; i < d; i++)
        temp.push_back(a[i]);

    for (int i = 0; i < n - d; i++)
    {
        a[i] = a[d + i];
    }

    for (int i = n - d; i < n; i++)
    {
        a[i] = temp[i - (n - d)];
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
    {
        cout << "Enter " << i << " th Element: ";
        cin >> a[i];
    }

    int d;
    cout << "Enter d value: ";
    cin >> d;

    rotateBy_D_places(a, n, d);

    // Printing the array

    for (int i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
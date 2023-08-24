#include <iostream>
using namespace std;

void rotateByOnePlace(int a[], int n)
{
    int temp = a[0]; // for storing the first element

    // left shift remaining elements
    for (int i = 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }

    a[n - 1] = temp;
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

    rotateByOnePlace(a, n); // function call

    // answer
    for (int i : a)
        cout << i << " ";

    cout << endl;

    return 0;
}
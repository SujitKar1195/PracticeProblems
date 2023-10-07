#include <iostream>
using namespace std;

int findMissing(int a[], int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ (a[i]);
    }
    xor1 = xor1 ^ (n);
    return xor1 ^ xor2;
}

int main()
{
    int n;
    cout << "Enter the size of the array:  ";
    cin >> n;
    // creation of the array
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int num = findMissing(a, n);

    cout << "The missing number is: " << num << endl;

    return 0;
}
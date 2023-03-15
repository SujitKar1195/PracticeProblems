#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        int k = 1;
        while (k <= (i-j))
        {
            cout << "  ";
            k++;
        }
        while (j <= (n - i + 1))
        {
            cout << "* ";
            j++;
        }
        cout << endl;
    }

    return 0;
}
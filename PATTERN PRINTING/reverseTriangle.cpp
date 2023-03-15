#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= (n - i))
        {
            cout << " ";
            j++;
        }
        int k = 1;
        while (k <= i)
        {
            cout << "*";
            k++;
        }
        cout << endl;
    }

    return 0;
}
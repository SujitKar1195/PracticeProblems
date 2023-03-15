#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= i)
        {
            cout << count++ << " ";
            j++;
        }
        cout << endl;
    }

    return 0;
}
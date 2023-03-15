#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j <= i+i-1)
        {
            cout << j++ << " ";
        }
        cout << endl;
    }

    return 0;
}
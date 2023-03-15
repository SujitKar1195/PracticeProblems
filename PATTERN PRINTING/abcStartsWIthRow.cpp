#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    char x = 'A';
    char y  = x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout <<y++<<" ";
        }
        cout << endl;
        x++;
        y = x;
    }

    return 0;
}
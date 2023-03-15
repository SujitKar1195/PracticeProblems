#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    char x = 'A';
    int i = 1;
    while (i <= n)
    {
        x = 'A' + n - i ;
        int j = 1;
        while (j <= i)
        {
            cout << x++ << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // int j = 1;
        // int k = i;
        int j = i;
        while (j >= 1)
        {
            cout << j-- << " ";
            
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void ans(vector<int> v)
{
    int evenSum = 0;
    int oddSum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
        {
            evenSum += v[i];
        }
        else
        {
            oddSum += v[i];
        }
    }

    cout << "evenSum - oddSum = " << evenSum - oddSum << endl;
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ans(v);

    return 0;
}
#include <iostream>
using namespace std;

int sqrt(int n)
{
    if (n < 2)
        return n;
    int start = 1, end = n, ans, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid == (n / mid))
            return mid;
        else if (mid < (n / mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    cout << sqrt(n) << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int ans(vector<int> v, int x)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i] > x)
            count++;
    return count;
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    int x;
    cout << "Number Baata jaldi : ";
    cin >> x;
    cout << ans(v, x) << endl;
}
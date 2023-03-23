/*
    Author: Sujit Kar
    Date: 26/02/2023
    Topic: first_negativeINteger_IN_every_indow_size_K(optimized)
    Time Complexity: O(n)
    I/P:
        size: 5
        arr: -8 2 - 6 1 0
        window_size: 3
    O/P:
        -8 -6 -6
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

void result(int *a, int n, int k)
{
    vector<long> v;
    list<int>l;
    int i = 0, j = 0;
    while(j<n)
    {
        if(a[j]<0)
        {
            l.push_back(a[j]);
        }
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            if(l.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(l.front());
                if(a[i]<0)
                l.pop_front();
            }
            i++,j++;
        }
    }
    

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cout << "Enter test cases : ";
    cin >> t;

    while (t--)
    {
        int n;
        cout << "Array Size: ";
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int k;
        cout << "Enter window(subarray) size: ";
        cin >> k;
        result(a, n, k);
    }

    return 0;
}
/*In Frequency Count, we have to count how many times the element is present in the list*/

// Steps to solve:
/*
**Input array is given**
1. First we have to know which is the largest element in the given input array.
so that we can create an array of that size.
2.Initialize the array with the value 0
3. Using a loop go through the input array and incrementing the value in the auxillary array for all occurences of elements.
4. There will be given some queries in which we will answer how many times the element is occuring
*/

// Note that: we can create an array inside the main is the size of 10^6; If we exceeded it will throw an error. and if we globally declare it can be of size of 10^7

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    // creating input array
    int a[n];

    // taking input
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Hashing

    int m = *max_element(a, a + n);

    int hash[m + 1] = {0}; // creation of the hash array and initialize with 0

    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++; // incrementing the count for all the occurence of element
    }

    int q;
    cout << "How many queries do you have: ";
    cin >> q;

    while (q--)
    {
        int no;
        cout << "Which number You are searching for: ";
        cin >> no;
        if (no <= m)
            cout << no << " is occuring " << hash[no] << " times" << endl;
        else
            cout << "Crossed the index bound\n";
    }
    cout << "The program is ended" << endl;

    return 0;
}
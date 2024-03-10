
/*
	Author: Sujit Kar
	Date: 10/03/2024
	Topic: Minimum characters to be added at front to make string palindrome.
	Time Complexity: O(N)
	Space Complexity: O(N)
	I/P: abc
	O/P: 2
*/

#include <bits/stdc++.h>
using namespace std;


void findLps(vector<int> &lps, string &s)
{
    int preIndex = 0;
    int sufIndex = 1;

    while (sufIndex < s.size())
    {
        if (s[preIndex] == s[sufIndex])
        {
            lps[sufIndex] = preIndex + 1;
            preIndex++;
            sufIndex++;
        }
        else
        {
            if (preIndex == 0)
            {
                lps[sufIndex] = 0;
                sufIndex++;
            }
            else
            {
                preIndex = lps[preIndex - 1];
            }
        }
    }
}

int charToAdd(string &s){
	string rev = s;
	reverse(rev.begin(), rev.end());
	string lpsString = s + "$" + rev;

	vector<int> lps(lpsString.size(), 0);
	findLps(lps, lpsString);
	
	return s.size() - lps[lpsString.size() - 1];
}

int main()
{
	string s;
	cout << "string: ";
	getline(cin, s);

	cout << charToAdd(s) << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int ans = INT_MIN;

    while (j < s.length())
    {
        mp[s[j]]++;

        // if unique characters are less than given size;
        if (mp.size() < k)
            j++;

        // if unique characters equal to the given size;
        else if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        // if(unique characters are greater than the given size)
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;        // decrement frequency
                if (mp[s[i]] == 0) // if(unique char count == 0) then remove the element from the map.
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    if (ans == INT_MIN)
        return -1;
    return ans;
}

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    int k;
    cout << "Enter k unique characters: ";
    cin >> k;

    int ans = longestKSubstr(s, k);
    cout << "The answer is : " << ans << endl;

    return 0;
}

/*
	Author: Sujit Kar
	Date: 10/03/2024
	Topic: find all the occurences of a pattern in a string.
	Time Complexity: O(N)
	Space Complexity: O(N)
	I/P: text: geeksforgeeks, pattern: geek
	O/P: 0 8
*/

#include <iostream>
#include <vector>
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

vector<int> allOccurences(string &s, string &p){
	int n = s.size(); // text length
	int m = p.size(); // pattern length
	vector<int> lps(m, 0); // lps table for pattern string
	findLps(lps, p); // calculating lps
	vector<int> ans;
	int first = 0;
	int second = 0;
	
	while(first < n){
		if(s[first] == p[second]){ // if matches then increment two pointers
			first++;
			second++;
			if(second == m){ // if second pointer ends with size of its string it means string is found.
				ans.push_back(first - second);
				first = first - second + 1;
				second = 0;
			}
		}
		else if(second == 0) first++; // if seconds points to the first character then increment first pointer
		else
			second = lps[second - 1];
	}
	
	if(ans.size() == 0)
		ans.push_back(-1);
	return ans;
}

int main(){
	string s;
	cout << "Text: ";
	getline(cin, s);
	
	string pattern;
	cout << "Pattern: ";
	getline(cin, pattern);

	vector<int> ans =  allOccurences(s, pattern);
	for(int i: ans){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
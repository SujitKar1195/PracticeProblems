#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateSubsequences(string &s, int index, int length, vector<string> &ans, string &temp)
{
	if(index == length){
		ans.push_back(temp);
		return;
	}
	
	// not taking
	generateSubsequences(s, index + 1, length, ans, temp);
	temp += s[index];
	// taking
	generateSubsequences(s, index + 1, length, ans, temp);
	temp.pop_back();
}

int main()
{
	string s;
	cout << "String : ";
	cin >> s;
	vector<string> ans;
	string temp;
	generateSubsequences(s, 0, s.length(), ans, temp);
	
	for(string &temp : ans)
	{
		cout << ":->" << temp << endl;
	}
}
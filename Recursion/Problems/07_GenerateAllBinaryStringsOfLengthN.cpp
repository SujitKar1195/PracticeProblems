#include <bits/stdc++.h>
using namespace std;


void generate(int index, int n, string &temp, vector<string> &ans){
	if(index == n){
		ans.push_back(temp);
		return;
	}

	temp += "0";
	generate(index + 1, n, temp, ans);
	temp.pop_back();
	temp += "1";
	generate(index + 1, n, temp, ans);
	temp.pop_back();
}

int main()
{
	int n;
	cout << "Size: ";
	cin >> n;

	vector<string> ans;
	string temp;
	generate(0, n, temp, ans);
	
	for(string &s : ans){
		cout << ":->" << s << endl;
	}
	return 0;
}
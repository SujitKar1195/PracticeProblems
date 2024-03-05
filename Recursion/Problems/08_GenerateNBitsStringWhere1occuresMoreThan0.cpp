#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
If every steps we will make a observation where in each step we have to add bits so that number of one's occur more or equal to zero's
*/
void generate(int zeroCount, int oneCount, int n, vector<string> &ans, string &temp){
	if(zeroCount + oneCount >= n){
		ans.push_back(temp);
		return;
	}
	
	if(oneCount < n){
		temp += "1";
		generate(zeroCount, oneCount + 1, n, ans, temp);
		temp.pop_back();
	}
	
	if(zeroCount < oneCount){
		temp += "0";
		generate(zeroCount + 1, oneCount, n, ans, temp);
		temp.pop_back();
	}
}

int main()
{
	int n;
	cout << "Bit: ";
	cin >> n;
	
	vector<string> ans;
	string temp = "";
	int zeroCount = 0;
	int oneCount = 0;
	generate(zeroCount, oneCount, n, ans, temp);
	for(string &s: ans){
		cout << ":->" << s << endl;
	}
	cout << endl;

	return 0;
}
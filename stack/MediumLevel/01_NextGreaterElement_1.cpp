#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
void findNextGreater(vector<int> &a, int n, vector<int> &ans){
	for (int i = 0; i < n - 1; i++){
		int isNextGreaterPresent = false;
		int element = -1;
		for(int j = i + 1; j < n; j++){
			if(a[j] > a[i]){
				isNextGreaterPresent = true;
				element = a[j];
				break;
			}
		}
		
		ans[i] = element;
	}
}

tc-> O(n^2)
sc -> O(1)
*/

void findNextGreater(vector<int> &a, int n, vector<int> &ans){
	stack<int>st;
	int nextMaxiIndex = 0;
	for (int i = 0; i < n; i++){
		
	}
}

int main(){
	int n;
	cout << "size: ";
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> ans(n, -1);
	
	findNextGreater(a, n, ans);
	
	for(int n: ans){
		cout << n << " ";
	}
}
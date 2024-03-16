#include <bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> &arr, int n){
	int ans = 0;
	int largestElement = arr[n - 1];
	for (int i = n - 2; i >= 0; i--){
		if(largestElement < arr[i])
			largestElement = arr[i];
		else{
			ans = max(ans, largestElement - arr[i]);
		}
	}
	return ans;
}

int main()
{
	int n;
	cout << "size: ";
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << maxDiff(arr, n) << endl;

	return 0;
}
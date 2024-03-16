#include <bits/stdc++.h>
using namespace std;

int divide(vector<int> &arr, int size){
	int totalSum = 0;
	for (int i = 0; i < size; i++)
		totalSum += arr[i];

	int prefixSum = 0;
	for (int i = 0; i < size; i++){
		prefixSum += arr[i];
		int k = totalSum - prefixSum;
		if(k == prefixSum)
			return i;
	}

	return -1;
}

int main()
{
	int n;
	cout << "size: ";
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int pivotIndex = divide(arr, n);
	cout << pivotIndex << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

void findSubsetSum(int index, int n, int arr[], int sum, int tSum, int &count)
{
	if(index == n){
		if(sum == tSum)
			count++;
		return;
	}
	
	// not taking
	findSubsetSum(index + 1, n, arr, sum, tSum, count);
	sum += arr[index];
	findSubsetSum(index + 1, n, arr, sum, tSum, count);
	sum -= arr[index];
}

int main()
{

	int n;
	cout << "Size: ";
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	int tSum;
	cout << "Enter target sum : ";
	cin >> tSum;
	int count = 0;
	findSubsetSum(0, n, a, sum, tSum, count);
	cout << "Total Count = " << count << endl;
	return 0;
}
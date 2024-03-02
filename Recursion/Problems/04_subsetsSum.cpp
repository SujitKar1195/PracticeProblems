#include <bits/stdc++.h>
using namespace std;

void findSubsetSum(int index, int n, int arr[], int sum, vector<int> &sumList)
{
	if(index == n){
		sumList.push_back(sum);
		return;
	}
	
	// not taking
	findSubsetSum(index + 1, n, arr, sum, sumList);
	sum += arr[index];
	findSubsetSum(index + 1, n, arr, sum, sumList);
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

	vector<int> sumList;
	int sum = 0;

	findSubsetSum(0, n, a, sum, sumList);
	cout << "Result : " << endl;
	for(auto sum : sumList)
		cout << ":-> "<<sum << endl;

	return 0;
}
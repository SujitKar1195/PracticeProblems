#include <bits/stdc++.h>
using namespace std;

int countWays(int a[], int n, int sum){
	if(sum < 0) return 0;
	if(sum == 0) return 1;
	
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans = ans + countWays(a, n, sum - a[i]);
	}

	return ans;
}

int main()
{
	int n;
	cout << "Size: ";
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int sum;
	cout << "Sum : ";
	cin >> sum;
	int count = countWays(a, n, sum);
	cout << count << endl;

	return 0;
}
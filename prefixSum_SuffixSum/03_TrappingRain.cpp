#include <iostream>
#include <vector>
using namespace std;
/*
int totalWater(vector<int> &a, int n)
{
	vector<int> preMax(n, -1);
	vector<int> sufMax(n, -1);

	// prefix maximum calculation
	int preMaxi = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > preMaxi)
		{
			preMaxi = a[i];
			preMax[i] = -1;
		}
		else
		{
			preMax[i] = preMaxi;
		}
	}

	// suffix maximum calculation
	int sufMaxi = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] > sufMaxi)
		{
			sufMaxi = a[i];
			sufMax[i] = -1;
		}
		else
		{
			sufMax[i] = sufMaxi;
		}
	}

	// calculate total water that can be stored
	int total = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int minHeight = min(preMax[i], sufMax[i]);
		if (minHeight >= a[i])
		{
			total = total + (minHeight - a[i]);
		}
	}

	return total;
}

TC-> O(n + n + n) = O(3n) ~ O(n)
SC-> O(n + n) = O(2n) ~ O(n)
??? Can we further optimize this code ????

*/

int totalWater(vector<int> &a, int n)
{
	//> Approach
	// i. find the index of the tallest building
	// ii. traverse from the leftside, calculate total water by subtracting current height from leftmax height, till previouse index of the tallest building
	// iii. now traverse from the rightside, calculate total water by subtracting current height from rightmax height, till before the height building.

	// find the index of the tallest building
	int tallIndex = -1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			tallIndex = 0;
		}
		else
		{
			if (a[i] >= a[tallIndex])
				tallIndex = i;
		}
	}
	cout << tallIndex << endl;

	int total = 0;
	// calculate from the leftside
	int leftMax = a[0];
	for (int i = 1; i < tallIndex; i++)
	{
		if (leftMax > a[i])
			total += (leftMax - a[i]);
		else
			leftMax = a[i];
	}

	// calculate from the rightside
	int rightMax = a[n - 1];
	for (int i = n - 2; i > tallIndex; i--)
	{
		if (rightMax > a[i])
		{
			total += (rightMax - a[i]);
		}
		else
			rightMax = a[i];
	}
	return total;

	// tc -> O(3n) ~ O(n);
	// sc -> O(1), because only using constant variables, tallindex, leftmax and rightmax
}

int main()
{
	int n;
	cout << "Size: ";
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << totalWater(a, n) << endl;
	return 0;
}
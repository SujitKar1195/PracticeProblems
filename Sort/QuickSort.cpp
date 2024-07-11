#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
	int pivot = arr[end];
	int pos = start;

	for (int i = start; i <= end; i++)
	{
		if (arr[i] <= pivot)
			swap(arr[i], arr[pos++]);
	}
	return pos - 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
  if (start >= end)
    return;

  int pivotIndex = partition(arr, start, end);
  quickSort(arr, start, pivotIndex - 1);
  quickSort(arr, pivotIndex + 1, end);
}

int main()
{
	int n;
	cout << "Enter the size: ";
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n - 1);
	for (int num : arr)
		cout << num << " ";

	cout << endl;
	return 0;
}

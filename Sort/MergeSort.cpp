#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
  vector<int> temp(end - start + 1);
  int left = start, right = mid + 1;
  int index = 0;
  while (left <= mid && right <= end)
  {
    if (arr[left] <= arr[right])
    {
      temp[index] = arr[left];
      left++, index++;
    }
    else
    {
      temp[index] = arr[right];
      right++, index++;
    }
  }

  while (left <= mid)
  {
    temp[index++] = arr[left++];
  }
  while (right <= end)
  {
    temp[index++] = arr[right++];
  }

  // copying elements from temp to the original array
  index = 0;
  while (start <= end)
  {
    arr[start++] = temp[index++];
  }
}

void mergeSort(vector<int> &arr, int start, int end)
{
  if (start >= end)
    return;
  int mid = start + (end - start) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

int main()
{
  int n;
  cout << "Enter size: ";
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  mergeSort(arr, 0, n - 1);
  for (int num : arr)
    cout << num << " ";

  return 0;
}
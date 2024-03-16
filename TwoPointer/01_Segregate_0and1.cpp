#include <bits/stdc++.h>
using namespace std;

// best approach -> O(n)
//void segregate(vector<int> &arr, int size){
//	int start = 0;
//	int end = size - 1;
	
//	while(start < end){
//		if(arr[start] == 0) start++;
//		else if(arr[end] == 1) end--;
//		else{
//			swap(arr[start], arr[end]);
//			start++;
//			end--;
//		}
		
//	}
//}

// less Best Approach -> O(n + n)

//void segregate(vector<int> &arr, int size){
//	int count0 = 0;
//	int count1 = 0;
//	int index = 0;
//	while(index < size){
//		if(arr[index] == 0) 
//			count0++;
//		else
//			count1++;
//		index++;
//	}

//	for (int i = 0; i < count0; i++)
//		arr[i] = 0;
//	for (int i = count0; i < size; i++)
//		arr[i] = 1;
//}

// sorting -> O(nlogn)
void segregate(vector<int> &arr, int size){
	sort(arr.begin(), arr.end());
}
int main()
{
	int size;
	cout << "Size: ";
	cin >> size;
	vector<int> arr(size);
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	segregate(arr, size);

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;

	return 0;
}
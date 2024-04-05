/*
You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with i) each student getting at least one book.
Out of all the permutations, ii) the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Input:
	N = 4
	A[] = {12,34,67,90}
	M = 2
Output:113
	Explanation:Allocation can be done in 
	following ways:
		{12} and {34, 67, 90} Maximum Pages = 191
		{12, 34} and {67, 90} Maximum Pages = 157
		{12, 34, 67} and {90} Maximum Pages = 113.
	Therefore, the minimum of these cases is 113,
	which is selected as the output.
	
	TC -> O(nlogn), logn for binary search and n time for inside sum of the array
	SC -> O(1)

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bookAllocation(vector<int> &a, int size, int student){
	if(size < student)
		return -1;
	int start = *max_element(a.begin(), a.end()); // book with max page
	int end = 0; // sum of all pages
	for(int i: a)
		end += i;
	int ans = -1;
	while(start <= end)
	{
		int mid = start + (end - start) / 2;

		int pages = 0, count = 1;
		for (int i = 0; i < size; i++){
			pages += a[i];
			
			if(pages > mid){
				pages = a[i];
				count++;
			}
		}
		
		if(count <= student){
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	return ans;
}

int main()
{
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int student;
	cout << "No. of Students: ";
	cin >> student;

	cout << bookAllocation(a, n, student);
	return 0;
}
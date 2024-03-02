#include <iostream>
#include <vector>
using namespace std;


void generateAllSubsequences(int arr[], int index, int size, vector<vector<int>> &ans,
vector<int> &temp)
{
	if(index == size){
		ans.push_back(temp);
		return;
	}
	
	// not included
	generateAllSubsequences(arr, index + 1, size, ans, temp);
	// push into the temp vector
	temp.push_back(arr[index]);
	// included
	generateAllSubsequences(arr, index + 1, size, ans, temp);
	// pop_back from end of the temp vector
	temp.pop_back();
}

int main()
{
	int a[] = {1, 2, 3};
	vector<vector<int>> ans;
	vector<int> temp;
	generateAllSubsequences(a, 0, 3, ans, temp);
	
	for(auto &li : ans)
	{
		cout << ":->";
		for(int i: li){
			cout << i << " ";
		}
		cout << endl;
	}
}
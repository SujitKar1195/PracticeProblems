#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printAllofSizeK(vector<int> &a, int n, int k)
{
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		if(q.size() < k){
			q.push(i);
		}
		if(q.size() == k){
			int x = k;
			while(x--)
			{
				cout << a[q.front()] << " ";
				q.push(q.front());
				q.pop();
			}
			cout << endl;
			q.pop();
		}
	}
}

int main()
{
	int n;
	cout << "size: ";
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int k;
	cout << "window size: ";
	cin >> k;

	printAllofSizeK(a, n, k);

	return 0;
}
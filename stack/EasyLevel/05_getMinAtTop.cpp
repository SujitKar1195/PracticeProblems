#include <bits/stdc++.h>
using namespace std;

void stackPush(int a[], int n, stack<int> &st){
	int mini = INT_MAX;
	for(int i = 0; i < n; i++){
		mini = min(a[i], mini);
		st.push(mini);
	}
}

void getMinAtTop(stack<int> &st){
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Size: ";
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	stack<int> st;
	stackPush(a, n, st);
	getMinAtTop(st);

	return 0;
}
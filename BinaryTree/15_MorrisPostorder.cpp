#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data = d;
		left = right = NULL;
	}
};

Node *createTree()
{
	queue<Node *> q;
	Node *p, *t;
	Node *root;
	cout << "Enter root->data: " << endl;
	int x;
	cin >> x;
	root = new Node(x);
	q.push(root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();

		cout << p->data << " 's left child:\n";
		int x;
		cin >> x;
		if (x != -1)
		{
			t = new Node(x);
			p->left = t;
			q.push(t);
		}

		cout << p->data << " 's right child:\n";
		cin >> x;
		if (x != -1)
		{
			t = new Node(x);
			p->right = t;
			q.push(t);
		}
	}

	return root;
}

vector<int> morrisPostorderTraversal(Node *root)
{
	vector<int> ans;

	// data
	// right
	// left
	// reverse
	while (root)
	{
		if (!root->right)
		{
			ans.push_back(root->data);
			root = root->left;
		}
		else
		{
			// check whether the left subtree is traversed or not
			// if rightmost node of the root's current left node is equal to root then
			// left subtree is already traversed.
			// else, if rightmost node the root's current left node is pointing to null then
			// left subtree is not traversed yet.

			Node *cur = root->right;
			while (cur->left && cur->left != root)
			{
				cur = cur->left;
			}

			// left subtree is not traversed yet
			if (cur->left == NULL)
			{
				ans.push_back(root->data);
				cur->left = root;	// so that after traversing all the nodes below we can have the access of the current and right subtree.
				root = root->right; // explore left
			}
			else
			{
				// if left subtree is already traversed then unlink the rightmost with root

				cur->left = NULL;
				root = root->left;
			}
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	Node *root = createTree();
	vector<int> ans = morrisPostorderTraversal(root);

	for (int x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}

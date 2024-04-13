#include <iostream>
#include <queue>
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

vector<int> morrisPreorderTraversal(Node *root)
{
	vector<int> ans;

	while (root)
	{
		if (!root->left)
		{
			ans.push_back(root->data);
			root = root->right;
		}
		else
		{
			// check whether the left subtree is traversed or not
			// if rightmost node of the root's current left node is equal to root then
			// left subtree is already traversed.
			// else, if rightmost node the root's current left node is pointing to null then
			// left subtree is not traversed yet.

			Node *cur = root->left;
			while (cur->right && cur->right != root)
			{
				cur = cur->right;
			}

			// left subtree is not traversed yet
			if (cur->right == NULL)
			{
				ans.push_back(root->data);
				cur->right = root; // so that after traversing all the nodes below we can have the access of the current and right subtree.
				root = root->left; // explore left
			}
			else
			{
				// if left subtree is already traversed then unlink the rightmost with root
				cur->right = NULL;
				root = root->right;
			}
		}
	}

	return ans;
}

int main()
{
	Node *root = createTree();
	vector<int> ans = morrisPreorderTraversal(root);

	for (int x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}

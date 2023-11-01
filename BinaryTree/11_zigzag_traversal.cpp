#include <bits/stdc++.h>
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

void levelorderTraversal(Node *p)
{
    queue<Node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->left)
        {
            cout << p->left->data << " ";
            q.push(p->left);
        }
        if (p->right)
        {
            cout << p->right->data << " ";
            q.push(p->right);
        }
    }

    cout << endl;
}

vector<vector<int>> zigzag(Node *root)
{
    vector<vector<int>> ans;

    queue<Node *> q;
    q.push(root);
    int lr = 1;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = lr ? i : size - i - 1;

            v[index] = temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        lr = 1 - lr;
        ans.push_back(v);
    }

    return ans;
}

void printZigZag(vector<vector<int>> &ans)
{
    int level = 1;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Level " << level++ << " : ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = createTree();

    vector<vector<int>> ans = zigzag(root);

    printZigZag(ans);

    return 0;
}

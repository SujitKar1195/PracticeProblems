/*
    Author: Sujit Kar
    Date: 26/06/2023
    Topic: Count the number of Full nodes
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

/*

Discuss:

    *Leaf Node means which node has both left child and right child.

    Steps to solve:
        1.Starting from root node,Using Level Order Traversal search for those nodes whose left and right node is not NULL;
        2. Use Queue for storing nodes.

*/

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

int countNumberOfFullNodeInBTLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    Node *temp = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left && temp->right)
        {
            count++;
        }

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return count;
}
int main()
{
    Node *root = createTree();

    cout << "Trees Data:\n";
    levelorderTraversal(root);

    int count = countNumberOfFullNodeInBTLevelOrder(root);
    cout << "Number of Full Nodes are: " << count << endl;

    return 0;
}
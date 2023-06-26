/*
    Author: Sujit Kar
    Date: 26/06/2023
    Topic: Find the diameter of the binary tree.
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

/*
Solution:
    *The Diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
    Algorithm:
        1.first calculate the diameter of left subtree and right subtree.
        2.return (maximum of both diameter) with +1.
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

int diameter(Node *root, int *ptr)
{
    int left = 0, right = 0;
    if (!root)
        return 0;
    left = diameter(root->left, ptr);
    right = diameter(root->right, ptr);
    if (left + right > *ptr)
        *ptr = left + right;
    return max(left, right) + 1;
}
int main()
{
    Node *root = createTree();
    cout << "Tree Data:\n";
    levelorderTraversal(root);
    int val = 0;
    cout << "Diameter = " << diameter(root, &val) << endl;
    return 0;
}
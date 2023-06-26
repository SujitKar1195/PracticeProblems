/*
    Author: Sujit Kar
    Date: 26/06/2023
    Topic: Given two Binary Trees, return true if they are structurally identical.
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

/*
Solution:
    Algorithm:
        1.If both trees are NULL then return true;
        2.If both tree are not NULL, then compare data and check left and right subtree structures.
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

int areStructurallySameTrees(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data && areStructurallySameTrees(root1->left, root2->left) && areStructurallySameTrees(root1->right, root2->right));
}
int main()
{
    Node *root1 = createTree();
    Node *root2 = createTree();

    cout << "Tree1 Data:\n";
    levelorderTraversal(root1);

    cout << "Tree2 Data:\n";
    levelorderTraversal(root2);

    if ((areStructurallySameTrees(root1, root2)))
    {
        cout << "Both Trees are structurally same.\n";
    }
    else
    {
        cout << "Not same.\n";
    }
    return 0;
}
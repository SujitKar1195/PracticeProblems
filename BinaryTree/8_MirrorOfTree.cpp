/*
    Author: Sujit Kar
    Date: 28/06/2023
    Topic: Given an algo. for converting a tree to its mirror. Mirror of a tree is another tree with left and right children of all non-leaf nodes interchanged.
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

/*
Discussion:
    What is the mirror of a Binary tree?
   => Mirror of a tree is another tree with left and right children of all non-leaf nodes interchanged.

   example:
            1
           / \
          2   3
 after mirror:
            1
           / \
          3   2

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

Node *mirrorOfBinaryTree(Node *root)
{
    if (!root)
        return NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left || temp->right)
        {
            Node *t = temp->left;
            temp->left = temp->right;
            temp->right = t;
        }

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return root;
}

int main()
{
    Node *root = createTree();
    cout << "Tree Data:\n";
    levelorderTraversal(root);
    root = mirrorOfBinaryTree(root);
    cout << "After mirroring the tree: " << endl;
    levelorderTraversal(root);
    return 0;
}
/*
    Author: Sujit Kar
    Date: 24/06/2023
    Topic: Delete an element from a Binary Tree
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

/*

Discuss:

    Steps to solve:
        1. Starting from root, search the node which we want to delete.
        2. find the deepest node in the tree.
        3. replace the deepest node's data with the node to be deleted.
        4. delete the deepest node.

     *****we assume that the binary tree has unique values*****
*/

#include <iostream>
#include <climits>
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

Node *deleteingNodeFromBinaryTree(Node *root, int delValue)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *delNode = NULL;
    Node *temp = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == delValue)
            delNode = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    if (delNode != NULL)
    {
        delNode->data = temp->data;
        temp->data = INT_MIN;

        return root;
    }
    else
        return NULL;
}
int main()
{
    Node *root = createTree();

    cout << "Before deletion:\n";
    levelorderTraversal(root);

    int data;
    cout << "Enter the data which is to be deleted:\n";
    cin >> data;
    Node *x = deleteingNodeFromBinaryTree(root, data);
    if (x == NULL)
        cout << data << " is not present in the binary tree.\n";
    else
    {
        cout << "After deletion:\n";
        levelorderTraversal(x);
    }

    return 0;
}
/*
    Author: Sujit Kar
    Date: 10/07/2023
    Topic: Zig Zag traversal
    Time Complexity: O(n)
    Space Complexity: O(n) + O(n) = O(2n) => O(n)
*/
#include <iostream>
#include <queue> // creating Tree
#include <stack> // zigzag traversal
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

void zigZagTraversal(Node *p)
{
    if (!p)
        return;
    Node *temp;
    int leftToRight = 1;
    stack<Node *> currentStack, nextStack;
    currentStack.push(p);
    while (!currentStack.empty())
    {
        temp = currentStack.top();
        currentStack.pop();

        if (temp)
        {
            cout << temp->data << " ";
            if (leftToRight)
            {
                if (temp->left)
                    nextStack.push(temp->left);
                if (temp->right)
                    nextStack.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextStack.push(temp->right);
                if (temp->left)
                    nextStack.push(temp->left);
            }
        }
        if (currentStack.empty())
        {
            leftToRight = 1 - leftToRight;
            currentStack.swap(nextStack);
        }
    }
}

int main()
{
    Node *root = createTree();
    cout << "Tree Data:\n";
    zigZagTraversal(root);
    return 0;
}
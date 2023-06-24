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

Node *findTheDeepestNode(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *temp = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return temp;
}
int main()
{
    Node *root = createTree();
    levelorderTraversal(root);

    Node *deepestNode = findTheDeepestNode(root);
    if (deepestNode == NULL)
        cout << "Hey Enter Data\n";
    else
        cout << "The Deepest Node of the Binary Tree is : " << deepestNode->data << endl;
    return 0;
}
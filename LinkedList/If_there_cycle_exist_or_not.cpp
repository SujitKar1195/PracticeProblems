/*
check whether the linked list is ended with a NULL or has a cycle;
Optimal approach
*/

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
} *first = NULL, *last = NULL;

void create(int *a, int n)
{
    first = new Node(a[0]);
    last = first;
    int i = 1;
    while (i < n)
    {
        Node *temp = new Node(a[i]);
        last->next = temp;
        last = temp;
        i++;
    }

    // last->next = first; this for creating a cycle
}
void display()
{
    cout << "Linked List elements : " << endl;
    Node *cur = first;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

bool Exists(Node *first)
{
    Node *fast = first, *slow = first;
    while(fast && fast->next)
    {
        slow  = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the linked list \n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    create(a, n);
    if (Exists(first))
    {
        cout << "Yes! it has cycle\n";
    }
    else
    {
        cout << "No its end with NULL\n";
    }
    return 0;
}
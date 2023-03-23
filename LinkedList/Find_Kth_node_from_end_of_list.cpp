/*
find the k th node from end of the list.

input:1->2->3->4->5;
k:2
output:4
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

int getLength(Node *first)
{
    int count = 0;
    if (first == NULL)
    {
        return 0;
    }
    Node *cur = first;
    while (cur)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

void findKthNode(int k)
{
    Node *fast, *slow;
    fast = slow = first;
    int size = getLength(first);
    int x = size - k + 1;
    if (x < 1 || x > size)
    {
        cout << "Position invalid\n";
        return;
    }
    int i = 0;
    while (i < k - 1)
    {
        i++;
        fast = fast->next;
    }

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << slow->data << endl;
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
    int k;
    cout << "Enter kth Node: ";
    cin >> k;
    findKthNode(k);
    return 0;
}
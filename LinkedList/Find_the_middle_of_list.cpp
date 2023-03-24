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

void middleNode(Node *first)
{
    Node *slow,*fast;
    slow = fast = first;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout <<"Middle Node of the linked list is : "<<slow->data<<endl;
}

int main()
{
    int n;
    cout << "Enter the size of the linked list \n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    create(a,n);
    middleNode(first);

    return 0;
}
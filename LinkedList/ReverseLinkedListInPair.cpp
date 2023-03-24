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
};

Node *create(int *a, int n)
{
    Node *first = new Node(a[0]);
    Node *last = first;
    int i = 1;
    while (i < n)
    {
        Node *temp = new Node(a[i]);
        last->next = temp;
        last = temp;
        i++;
    }
    return first;
}
void display(Node *first)
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

Node *reverseInPairs(Node *first)
{   Node *temp;
    if (first == NULL || first->next==NULL)
        return NULL;
    else
    {
        temp = first->next;
        first->next = temp->next;
        temp->next = first;
        first = temp;
        first->next->next = reverseInPairs(first->next->next);
        return first;
    }
    
}

int main()
{
    int n;
    cout << "Enter the size of the linked list \n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *first = create(a, n);
    Node *newP = reverseInPairs(first);
    display(newP);

    return 0;
}

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

Node * reverse(Node *first)
{
    // we will three pointer approach and we have to do some dry run also so that we can attain a position to understand
    Node *previous, *current, *Next; // creating three pointer
    previous = NULL;
    current = first;
    
    while (current != NULL)
    {
        Next = current->next;
        current->next =previous;
        previous = current;
        current = Next;
    }

    first = previous;
    return first;
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
    first = reverse(first);
    display();
    return 0;
}
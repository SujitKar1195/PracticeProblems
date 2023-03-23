
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

    // last->next = first; it is for creating a loop
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

void insertData(int data)
{
    Node *newNode = new Node(data);
    if (first == NULL || first->data > data)
    {
        newNode->next = first;
        first = newNode;
        return;
    }

    Node *cur = first;
    while (cur->next != NULL && cur->next->data < data)
    {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    return;
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
    int data;
    cout << "New data: ";
    cin >> data;
    insertData(data);
    display();
    return 0;
}
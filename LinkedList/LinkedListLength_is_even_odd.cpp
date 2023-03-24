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
bool evenOdd(Node *first)
{
    while (first && first->next)
    {
        first = first->next->next;
    }
    if (first)
        return false;
    return true;
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
    if (evenOdd(first))
        cout << "Length is Even\n";
    else
        cout << "Length is Odd\n";

    return 0;
}
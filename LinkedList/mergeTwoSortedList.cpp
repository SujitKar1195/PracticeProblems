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

Node *create(int *arr, int n)
{
    Node *head;
    Node *newNode = new Node(arr[0]);
    int i = 1;
    head = newNode;
    Node *last = head;
    if (n == 1)
    {
        return head;
    }
    while (i < n)
    {
        Node *newNode = new Node(arr[i]);
        last->next = newNode;
        last = newNode;
        i++;
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeLists(Node *first, Node *second)
{
    Node *result = NULL;
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;
    if (first->data <= second->data)
    {
        result = first;
        result->next = mergeLists(first->next,second);
    }
    else{
        result= second;
        result->next = mergeLists(first,second->next);
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter size 1st linked list \n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cout << "Enter size 2nd linked list \n";
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    Node *first = create(a, n);  // first head pointer for the first linked list
    Node *second = create(b, m); // second head pointer for the second linked list
    Node *result = mergeLists(first, second);
    display(result);

    return 0;
}
/*

Difficulty Easy
Company Tag:NA

Operations on Stack(Easy)

Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

The queries can be of 4 types:

i x: (adds element x in the stack).

r: (removes the topmost element from the stack).

h: Prints the topmost element.

f y: (check if the element y is present or not in the stack). Print "Yes" if present, else "No".


Example 1:

Input:
1
6
I 2
I 4
i 3
I 5
H
f 8

Output:
5
No
Explanation:
Inserting 2, 4, 3, and 5  onto the stack. Returning top element which is 5. Finding 8 will give No,
as 8 is not in the stack.

*/

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int x)
{
    s.push(x);
}

void remove(stack<int> &s)
{
    s.pop();
}

void headOf_Stack(stack<int> &s)
{
    cout << s.top() << endl;
}

int find(stack<int> s, int value)
{

    ;
    while (!s.empty())
    {
        int x = s.top();
        if (x == value)
        {

            return 1;
        }
        s.pop();
    }
    return 0;
}

int main()
{
    int t;
    cout << "Enter test case: ";
    cin >> t;
    while (t--)
    {

        stack<int> s;
        int q;
        cout << "How many queries You have : ";
        cin >> q;
        while (q--)
        {
            char ch;
            cin >> ch;

            if (ch == 'i')
            {
                int x;
                cin >> x;

                insert(s, x);
            }
            else if (ch == 'r')
            {
                remove(s);
            }
            else if (ch == 'h')
            {
                cout << "Head of the stack is: ";
                headOf_Stack(s);
            }
            else if (ch == 'f')
            {
                int x;
                cin >> x;
                if (find(s, x))
                    cout << x << " is present\n";
                else
                    cout << x << " is not present\n";
                cout << endl;
            }
        }
    }

    return 0;
}
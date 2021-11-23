#include <iostream>
#define MAX 100
using namespace std;
int stack[MAX];
int top = -1;
void push(int a)
{
    if (top != MAX)
    {
        stack[++top] = a;
    }
    else
    {
        cout << "Stack Overflow\n";
    }
}
void pop()
{
    if (top > -1)
    {
        cout << "Item popped: " << stack[top--] << endl;
    }
    else
    {
        cout << "Stack Underflow\n";
    }
}
void peep()
{
    if (top > -1)
    {
        cout << "Top element is: " << stack[top] << endl;
    }
    else
    {
        cout << "Stack Underflow\n";
    }
}
int main()
{
    cout << "We have a empty stack\n";
    while (1)
    {
        int ch;
        cout << "Enter a choice:\n";
        cout << "1. Push\n2. Pop\n3. Peep\n4.  Exit\n";
        cin >> ch;
        if (ch == 1)
        {
            int item;
            cout << "Enter item to be pushed: ";
            cin >> item;
            push(item);
        }
        else if (ch == 2)
        {
            pop();
        }
        else if (ch == 3)
        {
            peep();
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            cout << "INVALID INPUT.\nPlease try again.\n";
        }
    }
    return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#define MAX 100
using namespace std;
string stack[MAX];
int top = -1;
void push(string item)
{
    if (top != MAX)
    {
        stack[++top] = item;
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
bool can_operate()
{
    if (top > 0)
    {
        return true;
    }
    return false;
}
void power()
{
    int a = stoi(stack[top - 1]);
    int b = stoi(stack[top]);
    int ans = pow(a, b);
    pop();
    pop();
    push(to_string(ans));
}
void multiply()
{
    int a = stoi(stack[top - 1]);
    int b = stoi(stack[top]);
    int ans = a * b;
    pop();
    pop();
    push(to_string(ans));
}
void divide()
{
    int a = stoi(stack[top - 1]);
    int b = stoi(stack[top]);
    int ans = a / b;
    pop();
    pop();
    push(to_string(ans));
}
void mod()
{
    int a = stoi(stack[top - 1]);
    int b = stoi(stack[top]);
    int ans = a % b;
    pop();
    pop();
    push(to_string(ans));
}
void add()
{
    int a = stoi(stack[top - 1]);
    int b = stoi(stack[top]);
    int ans = a + b;
    pop();
    pop();
    push(to_string(ans));
}
void subtract()
{
    int a = stoi(stack[top - 1]);
    int b = stoi(stack[top]);
    int ans = a - b;
    pop();
    pop();
    push(to_string(ans));
}
bool isnum(string num_check)
{
    int i = 0;
    while (num_check[i] != '\0')
    {
        if (!isdigit(num_check[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}
void do_operation(string opr)
{
    if (can_operate() && opr[1] == '\0')
    {
        switch (opr[0])
        {
        case '^':
            power();
            break;
        case '*':
            multiply();
            break;
        case '/':
            divide();
            break;
        case '%':
            mod();
            break;
        case '+':
            add();
            break;
        case '-':
            subtract();
            break;
        default:
            cout << "ERROR\nInvalid operator entered.\n";
        }
    }
    else
    {
        cout << "ERROR OCCURED\nTry entering data again in a valid posfix manner.\n";
    }
}
int main()
{
    cout << "We have a empty stack\n";
    while (1)
    {
        int ch;
        cout << "Enter a choice:\n";
        cout << "1. Push\n2. Pop\n3. Peep\n4. Exit\n";
        cin >> ch;
        if (ch == 1)
        {
            string str_item;
            cout << "Enter item to be pushed: ";
            cin >> str_item;
            if (isnum(str_item))
            {
                push(str_item);
            }
            else
            {
                do_operation(str_item);
            }
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
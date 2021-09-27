//This program uses recursion to give factorial of a number.
#include<iostream>
using namespace std;
long fact(int a)
{
    long f = 1;
    return f = a == 0 ? 1 : a * fact(a-1);
}
int main()
{
    int x, factorial;
    cout<<"Enter a positive number: ";
    cin>>x;
    factorial = fact(x);
    cout<<"Factorial of "<<x<<" is "<<factorial<<endl;
    return 0;
}
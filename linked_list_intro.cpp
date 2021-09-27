//In this program a linked list with 5 nodes is created and displayed.
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node n1, n2, n3, n4 , n5;
main()
{
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;
    n4.data = 40;
    n5.data = 50;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    //Accessing next node from the previous.
    cout<<n1.data<<endl;
    cout<<n1.next->data<<endl;
    cout<<n2.next->data<<endl;
    cout<<n3.next->data<<endl;
    cout<<n4.next->data<<endl<<endl;

    //Accessing all nodes from the first node.
    cout<<n1.data<<endl;
    cout<<n1.next->data<<endl;
    cout<<n1.next->next->data<<endl;
    cout<<n1.next->next->next->data<<endl;
    cout<<n1.next->next->next->next->data<<endl;
    return 0;
}

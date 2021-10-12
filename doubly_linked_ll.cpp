#include<iostream>
using namespace std;
class Node{
    int val;
    Node *next;
    Node *prev;
public:
    void set_val(int data){ val = data; }
    int get_val(){ return val; }
    void set_next(Node *n){ next = n; }
    Node* get_next(){ return next; }
    void set_prev(Node *p){ prev = p;}
    Node* get_prev(){ return prev; }
};
class LinkedList{
    Node *head = NULL;
    Node *tail = NULL;
public:
    void create(){
        int n;      //number of elements
        cout<<"Limit: ";
        cin>>n;
        for(int i = 0; i < n; i++){
            int data;
            cout<<"Data: ";
            cin>>data;
            
            Node *tmp = new Node();
            tmp->set_val(data);
            tmp->set_next(NULL);
            tmp->set_prev(NULL);
            
            if(i == 0){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->set_next(tmp);
                tmp->set_prev(tail);
                tail = tmp;
            }
        }
    }
    void view(){
        Node *trav = head;
        cout<<"List: ";
        while(trav != NULL){
            cout<<trav->get_val()<<" ";
            trav = trav->get_next();
        }
        cout<<endl;
    }
};
int main()
{
    LinkedList l;
    int ch;
    while(1){
        cout<<"Enter an option :\n1.Create List.\t2.View List.\n";
        cout<<"Enter anything else to exit.\n";
        cin>>ch;
        if(ch == 1){
            l.create();
        }
        else if(ch == 2){
            l.view();
        }
        else break;
    }
    return 0;
}
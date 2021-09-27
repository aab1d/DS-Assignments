//p10: A linked list with each node having details of a Student(Name, Age, Marks).

#include<iostream>
using namespace std;

//Creating a node which stores the name, age and marks.
class Node{
public:
    string name;       
    int age;            
    float marks;
    Node *next;
};

Node *head = NULL, *tail = NULL;

//Function to create such linked list.
void create_list(){
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        
        Node *tmp = new Node();
        
        string name;
        int age;
        float marks;
        cout<<"Enter Name for Student "<<i+1<<" : ";
        cin>>name;
        cout<<"Enter Age for Student "<<i+1<<" : ";
        cin>>age;
        cout<<"Enter Marks for Student "<<i+1<<" : ";
        cin>>marks;

        tmp->name = name;
        tmp->age = age;
        tmp->marks = marks;
        tmp->next = NULL;
        if (i == 0){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }
}

//Function to view the list.
void view_list(){
    if(head == NULL){
        cout<<"\n*List is empty.*\n\n";
        return;
    }
    Node *t = head;

    cout<<"List:\n\n";
    while(t != NULL){
        cout<<"Name: "<<t->name<<"\nAge: "<<t->age<<"\nMarks: "<<t->marks<<endl<<endl;
        t = t->next;
    }
    cout<<endl;
}
int main()
{
    int ch;
    while(1){
        cout<<"Enter an option :\n1.Create List.\t2.View List.\n";
        cout<<"Enter anything else to exit.\n";
        cin>>ch;
        if(ch == 1){
            create_list();
        }
        else if(ch == 2){
            view_list();
        }
        else break;
    }
    return 0;
}
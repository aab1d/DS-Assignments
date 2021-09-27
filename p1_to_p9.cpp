//This program contains the the solution of problems from 1 to 9.
//p1: Viewing an Even linked list.
//p2: Viewing an Odd linked list.
//p3: Viewing linked list with only prime numbers.
//p4: Finding maximum and minimum values in the list.
//p5: Finding the frequency of an element.
//p6: Sorting the elements of list (both ascending and descending).
//p7: Deleting all instances of an element.
//p8: Modifing insert function such that it can insert before or after a particular element.
//p9: Modifing the create list such that it always creates list in sorted order

#include<iostream>
#include<math.h>
using namespace std;
class Node{
    int val;
    Node *next;
public:
    void set_val(int x){   val = x;}
    int get_val(){   return val; }
    void set_next(Node *n){   next = n; }
    Node* get_next(){   return next; }
};
Node *head = NULL, *tail = NULL;

//This function inserts new data BEFORE a particular element.
void insert_before(){

    int i, data;
    cout<<"Enter element BEFORE which data is to be inserted: ";
    cin>>i;     //stores the element after which new data is to be inserted

    cout<<"Enter new data: ";
    cin>>data;
    
    Node *tmp = new Node();
    tmp->set_val(data);
    Node *t = head;
    
    if (t->get_val() == i){
        tmp->set_next(t);
        head = tmp;
    }
    
    else if(head->get_next() == NULL){
        cout<<"\n***Element not found***\n\n";
    }
    
    else{
        while(t->get_next()->get_val() != i && t->get_next() != tail){
            t = t->get_next();
        }

        if(t->get_next()->get_val() == i){
            tmp->set_next(t->get_next());
            t->set_next(tmp);
        }
        else cout<<"\n***Element not found***\n\n";
    }
}

//This function inserts new data AFTER a particular element.
void insert_after(){
    int data, i;
    cout<<"Enter element AFTER which data is to be inserted: ";
    cin>>i;     //stores the element after which new data is to be inserted 
    
    cout<<"Enter new data: ";
    cin>>data;
    
    Node *tmp = new Node();
    tmp->set_val(data);
    Node *t = head;
    
    while (t->get_val() != i && t != tail){
        t = t->get_next();
    }
    
    if (t->get_val() == i){
        tmp->set_next(t->get_next());
        t->set_next(tmp);
        if (t == tail) 
            tail = tmp;
    }
    else cout<<"\n***Element not found***\n\n";
}

//This function prints the frequency of a particular element.
void view_frequency_val(){
    int data;
    cout<<"Enter element for checking its frequency: ";
    cin>>data;

    int count = 0;      //stores the frequency of element
    
    Node *t = head;
    
    while(t != NULL){
        if(t->get_val() == data){
            count++;
        }
        t = t->get_next();
    }
    cout<<"Frequency of "<<data<<" is "<<count<<endl;
}

//This function prints the maximum and minimum values present in the list.
void view_min_max_val(){
    if(head == NULL){
        cout<<"Empty List.\n";
        return;
    }
    else{
        Node *t = head;

        int min = t->get_val();
        int max = t->get_val();
        
        while(t != NULL){
            
            if(t->get_val() < min){
                min = t->get_val();
            }
            
            if(t->get_val() > min){
                max = t->get_val();
            }
            
            t = t->get_next();
        }
    cout<<"Min val: "<<min<<endl;
    cout<<"Max val: "<<max<<endl;
    }
}

//This function checks whether a number is prime or not.
bool isprime(int n){
    if(n < 2 )
        return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

//This function creates a linked list.
void create_list(){
    int n;      //limit of the elements
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    
    cout<<"Enter data:\n";
    for(int i = 0; i < n; i++){
        
        Node *tmp = new Node();
        
        int x;
        cin>>x;
        
        tmp->set_val(x);
        tmp->set_next(NULL);
        
        if (i == 0){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->set_next(tmp);
            tail = tmp;
        }
    }
}

//This function views a linked list.
void view_list(){
    Node *t = head;
    cout<<"\nList:\n";
    while(t != NULL){
        cout<<t->get_val()<<" ";
        t = t->get_next();
    }
    cout<<endl<<endl;
}

//This function views a linked list with only even numbers.
void view_even(){
    Node *t = head;
    cout<<"Even List:\n";
    while(t != NULL){
        if(t->get_val() % 2 == 0){
            cout<<t->get_val()<<" ";
        }
        t = t->get_next();
    }
    cout<<endl;
}

//This function views a linked list with only odd numbers.
void view_odd(){
    Node *t = head;
    cout<<"Odd List:\n";
    while(t != NULL){
        if(t->get_val() % 2 != 0){
            cout<<t->get_val()<<" ";
        }
        t = t->get_next();
    }
    cout<<endl;
}

//This function views a linked list with only prime numbers.
void view_prime(){
    Node *t = head;
    cout<<"Prime List:\n";
    while(t != NULL){
        if(isprime(t->get_val())){
            cout<<t->get_val()<<" ";
    }
    t = t->get_next();
    }
    cout<<endl;
}

//This function views a linked in ascending order.
void view_sorted_ascending(){
    if(head == NULL){
        return;
    }
    else{
        Node *t = head;
        Node *index = NULL;

        //Sorting in ascending order.
        while (t != NULL){
            index = t->get_next();
            while(index != NULL){
                if(t->get_val() > index->get_val()){
                    //Swapping the elements of the nodes  
                    int tmp = t->get_val();  
                    t->set_val(index->get_val());  
                    index->set_val(tmp);  
                }
                index = index->get_next();
            }
            t = t->get_next();
        }
        cout<<"After sorting in ascending order, ";
        view_list();
    }
}

//This function views a linked in descending order.
void view_sorted_descending(){
    if(head == NULL){
        return;
    }
    else{

        Node *t = head;
        Node *index = NULL;
        
        //Sorting in descending order
        while (t != NULL){
            index = t->get_next();
            while(index != NULL){
                if(t->get_val() < index->get_val()){
                    //Swapping the elements of the nodes  
                    int tmp = t->get_val();  
                    t->set_val(index->get_val());  
                    index->set_val(tmp);  
                }
                index = index->get_next();
            }
            t = t->get_next();
        }
        cout<<"After sorting in descending order, ";
        view_list();
    }
}

//This function deletes an element from the list.
void delete_val(){
    int data;
    cout<<"Enter Element to be deleted: ";
    cin>>data;
    
    Node *tmp = head;
    Node *prev = NULL;
    //Checking in the head.
    if(tmp != NULL && tmp->get_val() == data){
        head = tmp->get_next(); 
        delete tmp;
        return;
    }
    //Checking in the rest of List.
    else {
        while(tmp != NULL && tmp->get_val() != data){
            prev = tmp;
            tmp = tmp->get_next();
        }
        if(tmp == NULL){
            cout<<"Element not present\n";
            return;
        }
        prev->set_next(tmp->get_next());
        delete tmp;
    }
}

//This function deletes all instances of an element from the list.
void delete_all_val(){
    
    int data;
    cout<<"Enter the element to be deleted: ";
    cin>>data;

    Node *tmp = head;
    Node *prev = NULL;
    //Checks wether the element is present or not.    
    bool flag = false;

    //Checking for head node.
    if(tmp != NULL && tmp->get_val() == data){
        flag = true;
        head = tmp->get_next();
        delete tmp;
    }

    //Checking in the rest of list.
    while(tmp != NULL){
        if(tmp->get_val() == data) {
            flag = true;
        }
        if(tmp->get_val() != data){
            prev = tmp;
        }
        prev->set_next(tmp->get_next());
        tmp = tmp->get_next();
    } 
    if(flag)    cout<<"All instances deleted\n\n";
    else    cout<<"*** Element not found ***";
}

//This function creates a linked in ascending order.
void create_sorted_list(){
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    cout<<"Enter data:\n";

    for(int i = 0; i < n; i++){
        Node *tmp = new Node();
        
        int data;
        cin>>data;
        
        tmp->set_val(data);
        tmp->set_next(NULL);
        
        //The first element is both the head and tail.
        if (i == 0){
            head = tmp;
            tail = tmp;
        }
        
        //Arranging the elements in ascending order.
        else{
            Node *t = head, *prev;
            while (t != NULL && t->get_val() < data)
            {
                prev = t;
                t = t->get_next();
            }
            if (t == head)
            {
                tmp->set_next(head);
                head = tmp;
            }
            else if (t == NULL)
            {
                tail->set_next(tmp);
                tail = tmp;
            }
            else
            {
                tmp->set_next(t);
                prev->set_next(tmp);
            }
        }
    }
}
int main()
{
    int ch;
    bool flag = false;
    while(1){
        
        cout<<"Enter an option:\n";
        cout<<"1.Create List\n2.View List\n3.View Even List\n4.View Odd List\n5.View Prime List\n5.View Prime List\n6.View Min and Max Values\n7.View Frequency of an Element\n8.View Sorted List (Ascending)\n9.View Sorted List (Descending)\n10.Insert (Before Element)\n11.Insert (After Element)\n12.Create Sorted List\n13.Delete an Element\n14.Delete all instances of Element\n\n";
        cout<<"Enter 0 to exit.\n";
        cin>>ch;

        //Flag checks whether a list has been created.
        //For performing an operation or viewing, a list needs to be created first. 
        if(flag == false){
            if(ch == 1){
                create_list();
                flag = true;
            }
            else if(ch == 12){
                create_sorted_list();
                flag = true;
            }
            else cout<<"*** Create a list first. ***\n\n";
        }
        else{
        if(ch == 1){
            create_list();
            flag = true;
        }
        else if(ch == 2){
            view_list();
        }
        else if(ch == 3){
            view_even();
        }
        else if(ch == 4){
            view_odd();
        }
        else if(ch == 5){
            view_prime();
        }
        else if(ch == 6){
            view_min_max_val();
        }
        else if(ch == 7){
            view_frequency_val();
        }
        else if(ch == 8){
            view_sorted_ascending();
        }
        else if(ch == 9){
            view_sorted_descending();
        }
        else if(ch == 10){
            insert_before();
        }
        else if(ch == 11){
            insert_after();
        }
        else if(ch == 12){
            create_sorted_list();
            flag = true;
        }
        else if(ch == 13){
            delete_val();
        }
        else if(ch == 14){
            delete_all_val();
        }
        else if(ch == 0)
            return 0;
        else cout<<"\n*** Please enter a valid choice. ****\n\n";
        }
    }
    return 0;
}
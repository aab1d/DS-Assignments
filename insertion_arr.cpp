//This program inserts an extra element in an array.
#include<iostream>
using namespace std;
int main()
{
    int l;
    int arr[11];
    
    cout<<"Enter the elements of the array:\n";
    for(int i = 0; i < 10; i++)
        cin>>arr[i];
    
    cout<<"The elements of the array are:\n";
    for(int i = 0; i < 10; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\nEnter the location for insertion: ";
    cin>>l;
    //Emptying the element for insertion.
    for(int i = 10; i > l-1; i--)
        arr[i] = arr[i-1];
    
    cout<<"Enter the element to be inserted: ";
    cin>>arr[l-1];
    
    cout<<"Array after insertion:\n";
    for(int i = 0; i < 11; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
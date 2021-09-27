//This program delets a particular element in an array using its location.
#include<iostream>
using namespace std;
int main()
{
    int l;
    int arr[10];
    
    cout<<"Enter the elements of the array:\n";
    for(int i = 0; i < 10; i++)
        cin>>arr[i];
    
    cout<<"The elements of the array are:\n";
    for(int i = 0; i < 10; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\nEnter the location of the element to be removed: ";
    cin>>l;
    //Removing the element
    for(int i = l-1; i < 9; i++)
        arr[i] = arr[i+1];
    
    cout<<"Array after deleting the element:\n";
    for(int i = 0; i < 9; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
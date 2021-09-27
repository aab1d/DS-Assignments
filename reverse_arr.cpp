//This program reverses the elements of an input array.
#include<iostream>
using namespace std;
int main()
{
    int n; 
    int arr[100];
    cout<<"Enter size of array: "; 
    cin>>n;
    
    cout<<"Enter the elements of the array:\n";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<"The elements of the array are:\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    
    //Reversing elements.
    int j = n-1;
    for(int i = 0; i < n/2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        j--;
    }
    cout<<"\nArray after reversing:\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
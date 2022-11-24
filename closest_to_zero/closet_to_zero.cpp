#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   
    int arr[]={45,-79,8,2,-2,1,-1};
    int arr1[7];
    int len=sizeof(arr)/sizeof(arr[0]);
    // cout<<"The length is "<<len<<endl;

    cout<<"displaying elements of arr--------- ";
    for(int i=0; i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //obtaining absolute values: ";
    for (int i=0;i<len;i++)
    {   
        arr1[i]=abs(arr[i]);
    }
    cout<<endl;

    cout<<"displaying elements of arr1--------- ";
    for(int i=0; i<len;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    // cout<<"\nBefore sorting the array: ";
    // for (int i=0;i<len;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    cout<<"After sorting the array1: ";
    
    sort(arr1,arr1+len);
    for (int i=0;i<len;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    cout<<"\nThe closest element to 0 is : "<<arr1[0]<<endl;
    
    return 0;
}
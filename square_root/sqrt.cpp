#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    try
    {
        int i;
        cout<<"Enter the number: ";
        cin>>i;
        if(i>0)
        {
            cout<<"The square root of "<<i<<" is "<<sqrt(i)<<endl;
        }
        else
        throw (i);
        
    }
    catch(...)
    {
        cerr<<"not a valid integer.....Enter a positive integer "<<endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int is_prime(int i)
{
    if (i==0 || i==1)
    {
        cout<<i<<" is not a prime number"<<endl;
    }
        else if (i==2 || i==3 || i==5)
        {
            cout<<i<<" is a prime number"<<endl;
        }
        else if (i!=2 || i!=3 || i!=5)
        {
            if(i%2!=0 && i%3!=0 && i%5!=0) 
            {
                 cout<<i <<" is a prime number"<<endl;
            }
            else
            {
                cout<<i<<" is not a prime number"<<endl;
            }
             return i;
        }

}

int main()
{
    // cout<<"Enter a integer number :";
    is_prime(30);
    return 0;
}
#include <iostream>
#include <cassert>
#include <limits>
using namespace std;

int addition(float num1, float num2)
{
    cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl<<endl;
    return num1+num2;
}

// unsigned int addition(unsigned int num1, unsigned int num2)
// {
//     cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl<<endl;
//     return num1+num2;
// }

int subtraction(float num1, float num2)
{
    cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl<<endl;
    return num1-num2;
}

// unsigned int subtraction(unsigned int num1, unsigned int num2)
// {
//     cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl<<endl;
//     return num1-num2;
// }

int multiplication(float num1, float num2)
{
    cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
    return num1*num2;
}

// unsigned int multiplication(unsigned int num1, unsigned int num2)
// {
//     cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
//     return num1-num2;
// }

float division(float num1, float num2)
{
    float div=num1/num2;
    cout<<num1<<"/"<<num2<<"="<<div<<endl;
    return num1/num2;
}

int main()
{   
    float num1,num2;
    cout<<"Enter the 2 numbers : ";
    cin>>num1;
    cin>>num2;
    addition(num1, num2);
    subtraction(num1, num2);
    multiplication(num1, num2);
    division(num1, num2);
    return 0;
}
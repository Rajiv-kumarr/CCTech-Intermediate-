#include <iostream>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int* float_to_bit(float num )
{
    char* bits = reinterpret_cast<char*>(&num);
    int* ptr  = new int[4];
    for(int i=0;i<sizeof(num);++i)
    {
        ptr[i] = bitset<8> (bits[i]).to_ulong();
    }
    return ptr;
}

int main()
{
    float number;
    cout<<"Enter a float number: ";
    cin>>number;
    int* bit = float_to_bit(number);
    for(int i=0;i< 4;i++)
        cout <<bit[i] <<" ";
    delete [] bit;
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc==0)
    {
        cout<<"\n"<<endl;
    }
    else
    {
        for (int i=1;i<argc;++i)
        {
            cout<<argv[i];
        }
        cout<<endl;
    }
    return 0;
}
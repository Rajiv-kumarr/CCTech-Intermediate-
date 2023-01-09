#include "currency_converter.h"

using namespace std;

int main(int argc, char* argv[])
{
    currencyConverter cc;
    cc.runAllFunctions();

    char c;
    cout<<"Do you wish to continue (Press y/Y for Yes and n/N for No): ";
    cin>>c;
   
    if(c=='Y' || c=='y')
    {
        cc.runAllFunctions();
    }
    else
        cout<<"Thanks for your visit!! "<<endl;
}

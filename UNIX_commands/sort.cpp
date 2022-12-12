#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
    string c;
    vector<char> final_list;
    if(argc==1)
    {
        while(getline(cin,c))
        {
            for(int x: c)
            {
                final_list[x];
            }
        }
        sort(final_list.begin(),final_list.end());

    }

    else
    {
        ifstream output;
        string buffer;
        while(getline(output,buffer))
        {
            sort(buffer.begin(),buffer.end());
            cout<<buffer;
        }
    }

    return 0;
}

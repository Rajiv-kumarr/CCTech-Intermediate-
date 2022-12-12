#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    char c;
    if(argc==1)
    {
        while(cin.get(c))
        {
            cout<<c;
        }

    }
    else
    {
        char buffer;
        if(argc>1)
        {
            for(int i=1;i<argc;++i)
            {
                ifstream output(argv[i]);

                if(output.is_open())
                {
                    while(output.get(buffer))
                    {
                        cout<<buffer;
                    }
                    
                    output.close();

                }

                else
                cout<<argv[0]<<": "<<argv[1]<<": No such file or directory"<<endl;
                
            }
        }
        
    }
    return 0;
}

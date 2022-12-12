#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    string s;
    if(argc==1)
    {
        while(getline(cin,s))
        {
            cout<<s<<endl;
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
                if(argc>2)
                    cout<<"==> "<<argv[i]<<" <=="<<endl;

                if(output.is_open())
                {
                    int count=0;
                    while(output.get(buffer))
                    {
                        cout<<buffer;
                        count++;
                        if(count==20)
                            break;
                    }
                    cout<<endl;
                    
                    output.close();
                }

                else
                cout<<argv[0]<<": cannot open " <<"'"<<argv[i]<<"'"<<" for reading: No such file or directory"<<endl;
                
            }
        }
        
    }
    return 0;
}

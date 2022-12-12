#include <iostream>
#include <fstream>
#include <vector>
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
        string line;
        vector<string> lines;
        if(argc>1)
        {
            for(int i=1;i<argc;++i)
            {
                ifstream output(argv[i],ios::in);
                if(argc>2)
                    cout<<"==> "<<argv[i]<<" <=="<<endl;

                if(output.is_open())
                {
                   
                   while(getline(output,line)) 
                   {
                        lines.push_back(line);
                   }
                     if(lines.size()>=10)
                     {
                        for(auto i=lines.end()-10;i!=lines.end();++i)
                            cout<<*i<<endl;
                        
                     }
                     else
                     {
                        for(auto line:lines)
                            cout<<line<<endl;
                     }
                
                    output.close();
                }

                else
                cout<<argv[0]<<": cannot open " <<"'"<<argv[i]<<"'"<<" for reading: No such file or directory"<<endl;
                
            }
        }
        
    }
    return 0;
}

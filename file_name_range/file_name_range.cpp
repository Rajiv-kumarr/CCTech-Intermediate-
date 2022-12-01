#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string remove_path(const string& path)
{
    auto find_path_identifier=path.find_last_of("/");
    return path.substr(find_path_identifier+1);
}

string remove_substring(const string& file_name)
{
    string file_name1(file_name);
    string substring[]={"Tests","tests", "Test","test","Spec" ,"spec","Steps" ,"steps","Step","step"};
    
    for(string substr:substring)
    {
        auto find_substring=file_name1.find(substr);
        if(find_substring!=string::npos)
        {
            file_name1.erase(find_substring, substr.length());
        }
    }
    return file_name1;
}

string remove_extension(const string& file_name)
{
    string file_name1(file_name);
    auto find_extension=file_name1.find_last_of('.');

    if(find_extension!=string::npos)
    {
        file_name1 = file_name1.substr(0,find_extension);
    }
    return file_name1;
}

string remove_symbols(const string& file_name)
{
    string file_name1(file_name);
    char symbols[]={'-','_','.'};

    for(char symb: symbols)
    {
        auto find_first_index=remove(file_name1.begin(),file_name1.end(),symb);
        file_name1.erase(find_first_index, file_name1.end());
    }
    return file_name1;
}

string call_all_func(string path)
{
    string file_name1=remove_path(path);
    string file_name2=remove_substring(file_name1);
    string file_name3=remove_extension(file_name2);
    string file_name4=remove_symbols(file_name3);
    return file_name4;
}

void check_test_cases()
{
    string tests[]= {"src/Hiker_spec.re" ,"test/hiker_test.exs" ,"wibble/test/hiker_spec.rb" ,"hiker_steps.rb" ,"hiker_spec.rb" ,"test_hiker.rb" ,"test_hiker.py" ,"test_hiker.sh" ,
    "tests_hiker.sh" ,"test_hiker.coffee" ,"hiker_spec.coffee" ,"hikerTest.chpl" ,"hiker.tests.c" ,"hiker_tests.c" ,"hiker_test.c" ,"hiker_Test.c" ,"HikerTests.cpp" ,"hikerTests.cpp" ,
    "HikerTest.cs" ,"HikerTest.java" ,"DiamondTest.kt" ,"HikerTest.php" ,"hikerTest.js" ,"hiker-test.js" ,"hiker-spec.js" ,"hiker.test.js" ,"hiker.tests.ts" ,"hiker_tests.erl" ,"hiker_test.clj" ,
    "fizzBuzz_test.d" , "hiker_test.go" ,"hiker.tests.R" , "hikertests.swift" ,"HikerSpec.groovy" ,"hikerSpec.feature" ,"hiker.feature" ,"hiker.fun" ,"hiker.t" ,"hiker.plt" ,"hiker" 
    };

    for (string test_case:tests)
    {
        string final_name=call_all_func(test_case);
        auto find_name_first_index=test_case.find(final_name);
        cout<<test_case <<" : "<<" ["<<find_name_first_index<<","<<find_name_first_index+final_name.length()<<"], ("<<final_name<< ")"<<endl;
    }
}

int main()
{
    check_test_cases();
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
#include <sstream>
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

string check_test_cases(string test_case)
{
    string final_name=call_all_func(test_case);
    auto find_name_first_index=test_case.find(final_name);
    stringstream ss;
    ss<<"["<<find_name_first_index<<","<<find_name_first_index+final_name.length()<<"]";
    return ss.str();
}

void test_cases() 
{
    assert(check_test_cases("src/Hiker_spec.re")=="[4,9]");
    assert(check_test_cases("test/hiker_test.exs")=="[5,10]");
    assert(check_test_cases("wibble/test/hiker_spec.rb")=="[12,17]");
    assert(check_test_cases("hiker_steps.rb")=="[0,5]");
    assert(check_test_cases("hiker_spec.rb")=="[0,5]");
    assert(check_test_cases("test_hiker.rb")=="[5,10]");
    assert(check_test_cases("test_hiker.py")=="[5,10]");
    assert(check_test_cases("test_hiker.sh")=="[5,10]");
    assert(check_test_cases("tests_hiker.sh")=="[6,11]");
    assert(check_test_cases("test_hiker.coffee")=="[5,10]");
    assert(check_test_cases("hiker_spec.coffee")=="[0,5]");
    assert(check_test_cases("hikerTest.chpl")=="[0,5]");
    assert(check_test_cases("hiker.tests.c")=="[0,5]");
    assert(check_test_cases("hiker_tests.c")=="[0,5]");
    assert(check_test_cases("hiker_test.c")=="[0,5]");
    assert(check_test_cases("hiker_Test.c")=="[0,5]");
    assert(check_test_cases("HikerTests.cpp")=="[0,5]");
    assert(check_test_cases("hikerTests.cpp")=="[0,5]");
    assert(check_test_cases("HikerTest.cs")=="[0,5]");
    assert(check_test_cases("HikerTest.java")=="[0,5]");
    assert(check_test_cases("DiamondTest.kt")=="[0,7]");
    assert(check_test_cases("HikerTest.php")=="[0,5]");
    assert(check_test_cases("hikerTest.js")=="[0,5]");
    assert(check_test_cases("hiker-test.js")=="[0,5]");
    assert(check_test_cases("hiker-spec.js")=="[0,5]");
    assert(check_test_cases("hiker.test.js")=="[0,5]");
    assert(check_test_cases("hiker.tests.ts")=="[0,5]");
    assert(check_test_cases("hiker_tests.erl")=="[0,5]");
    assert(check_test_cases("hiker_test.clj")=="[0,5]");
    assert(check_test_cases("fizzBuzz_test.d")=="[0,8]");
    assert(check_test_cases("hiker_test.go")=="[0,5]");
    assert(check_test_cases("hiker.tests.R")=="[0,5]");
    assert(check_test_cases("hikertests.swift")=="[0,5]");
    assert(check_test_cases("HikerSpec.groovy")=="[0,5]");
    assert(check_test_cases("hikerSpec.feature")=="[0,5]");
    assert(check_test_cases("hiker.feature")=="[0,5]");
    assert(check_test_cases("hiker.fun")=="[0,5]");
    assert(check_test_cases("hiker.t")=="[0,5]");
    assert(check_test_cases("hiker.plt")=="[0,5]");
    assert(check_test_cases("hiker")=="[0,5]");
    std::cout << "Test cases passed" << std::endl;
}

int main()
{
    test_cases();
    return 0;
}

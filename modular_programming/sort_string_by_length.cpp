#include "sort_string_by_length.h"

void sort_string_by_length()
{
    string word;
    multimap<int,string>strings;
    while(getline(cin,word))
    {
        int length_of_word=word.size();
        strings.insert(pair<int, string>(length_of_word,word));
    }

    multimap<int, string>::iterator itr;

    for(itr=strings.begin();itr!=strings.end();++itr)
    {
        cout<<itr->second<<endl;
        // cout<<itr->first<<endl;
    }
}

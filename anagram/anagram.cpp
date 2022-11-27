#include <bits/stdc++.h>
using namespace std;

void permutation(string& word, int start, int last)
{
	if (start == last)
		cout << word << endl;
	else {
		for (int i = start; i <= last; i++) {

			swap(word[start], word[i]);

			permutation(word, start + 1, last);

			swap(word[start], word[i]);
		}
	}
}

int main()
{
	string str;
    cout<<"Enter the word: ";
    cin>>str;

	int len = str.size();

	permutation(str, 0, len - 1);
	return 0;
}


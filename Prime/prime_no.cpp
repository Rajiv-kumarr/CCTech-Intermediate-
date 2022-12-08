#include <iostream>
#include <cassert>
using namespace std;

unsigned int i,n;

bool Is_Prime()
{
    bool is_prime = true;

    if (n == 0 || n == 1) 
    {
      is_prime = false;
    }

    for (i = 2; i <= n/2; ++i) 
    {
      if (n % i == 0) 
      {
        is_prime = false;
        break;
      }
    }

    if (is_prime)
    {
      cout <<"Yes, a prime no."<<endl;
    }
    else
      cout << "Not a prime no."<<endl;

    return true;
  }

int main() 
{
  cout << "Enter a positive number: ";
  cin >> n;
  // Is_Prime();

  if(isdigit(Is_Prime())==true)
  {
    return true;
  }
  else
  cout<<"This is not a positive integer value"<<endl;

  return 0;
}

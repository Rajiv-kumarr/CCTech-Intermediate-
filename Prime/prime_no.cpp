#include <iostream>
#include <cassert>
using namespace std;

int i,n;

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
      cout << n << " is a prime no."<<endl;
    }
    else
      cout << n << " is not a prime no."<<endl;

    return true;
  }

int main() 
{
  cout << "Enter a number: ";
  cin >> n;
  Is_Prime();

  return 0;
}

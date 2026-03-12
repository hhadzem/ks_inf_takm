#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;

  int nzd = 1;

  for(int i=2;i<=min(a, b);i++)
  {
    if(a % i == 0 && b % i == 0)
      nzd = i;
  }

  cout << nzd << endl;

  return 0;
}

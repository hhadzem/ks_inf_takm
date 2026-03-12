#include <iostream>

using namespace std;

int main()
{
  long long A, B;
  cin >> A >> B;

  long long temp;

  // Euklidov algoritam
  while (B != 0)
  {
    temp = B;
    B = A % B;
    A = temp;
  }

  cout << A << endl;

  return 0;
}

#include <iostream>

using namespace std;

int main()
{
  int br = 0;
  string red;

  for (int i = 0; i < 3; i++)
  {
    cin >> red;
    for (int j = 0; j < 3; j++)
    {
      if (red[j] == '#')
      {
        br++;
      }
    }
  }

  cout << br << endl;

  return 0;
}

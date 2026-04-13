#include <iostream>

using namespace std;

int main()
{
  string red;
  cin >> red;

  int br = 0;
  for (int j = 0; j < 3; j++)
  {
    if (red[j] == '#')
    {
      br++;
    }
  }

  if (br == 0)
  {
    cout << 1 << endl;
  }
  else if (br == 1)
  {
    cout << 2 << endl;
  }
  else if (br == 2)
  {
    cout << 4 << endl;
  }
  else
  {
    cout << 6 << endl;
  }

  return 0;
}

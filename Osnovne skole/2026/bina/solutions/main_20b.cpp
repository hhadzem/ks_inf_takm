#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, k1, k2, k3;
  char t1, t2, t3;

  cin >> N >> t1 >> k1 >> t2 >> k2 >> t3 >> k3;

  // t1 je sigurno 'O'
  if (t2 == 'O' && t3 == 'O') {
    cout << k1 << endl;
  }
  else if (t2 == 'O' && t3 == 'D') {
    if (k2 > k3) {
      cout << k1 << endl;
    } else {
      cout << k1 - k2 + k3 << endl;
    }
  }
  else if (t2 == 'D' && t3 == 'D') {
    cout << k1 + k2 + k3 << endl;
  }
  else if (t2 == 'D' && t3 == 'O') {
    cout << k1 + k2 << endl;
  }

  return 0;
}

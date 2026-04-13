#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, K;
  char T;

  cin >> N;

  int zbir = 0;

  for(int i = 0; i < N; i++) {
    cin >> T >> K;

    zbir += K;
  }

  cout << zbir << endl;

  return 0;
}

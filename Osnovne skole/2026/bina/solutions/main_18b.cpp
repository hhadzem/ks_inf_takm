#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, K;
  char T;

  cin >> N;

  int maksimum = 0;

  for(int i = 0; i < N; i++) {
    cin >> T >> K;

    if(K > maksimum) {
      maksimum = K;
    }
  }

  cout << maksimum << endl;

  return 0;
}

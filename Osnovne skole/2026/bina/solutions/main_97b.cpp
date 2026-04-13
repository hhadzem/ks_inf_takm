#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, K;
  char T;

  cin >> N;

  int trenutno = 0; // Trenutni broj učenika na bini
  int maksimum = 0; // Maksimalan broj učenika koji su bili na bini

  for (int i = 0; i < N; i++) {
    cin >> T >> K;

    if (T == 'D') {
      trenutno += K; // Dolazi K učenika
      maksimum = max(maksimum, trenutno);
    } else {
      trenutno -= K; // Odlazi K učenika
    }
  }

  cout << maksimum << endl;

  return 0;
}

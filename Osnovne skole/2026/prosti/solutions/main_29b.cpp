#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  // Rjesenje samo za A = B (jedan zbir)
  // Koristi Eratostenovo sito
  int S = A; // A = B

  vector<bool> is_prime(S + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= S; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= S; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int count = 0;
  for (int p = 2; p < S; p++) {
    int q = S - p;
    if (q > p && is_prime[p] && is_prime[q]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

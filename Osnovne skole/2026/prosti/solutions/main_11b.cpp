#include <iostream>

using namespace std;

bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int A, B;
  cin >> A >> B;

  int count = 0;

  // Brute force: probaj sve parove (p, q) sa p < q
  // Radi samo za male vrijednosti (A = B <= 100)
  for (int p = 2; p <= B; p++) {
    for (int q = p + 1; q <= B; q++) {
      int s = p + q;
      if (s == A && is_prime(p) && is_prime(q)) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  // Eratostenovo sito za pronalaženje svih prostih brojeva do B
  vector<bool> is_prime(B + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= B; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= B; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Prefiksna suma prostih brojeva: prime_count[i] = broj prostih brojeva <= i
  vector<int> prime_count(B + 1, 0);
  for (int i = 1; i <= B; i++) {
    prime_count[i] = prime_count[i - 1] + (is_prime[i] ? 1 : 0);
  }

  // Za svaki prost broj p, odredi broj prostih brojeva q > p tako da je A <= p + q <= B
  // To znači: max(p + 1, A - p) <= q <= B - p
  long long count = 0;

  for (int p = 2; p <= B; p++) {
    if (!is_prime[p]) continue;

    int lo = max(p + 1, A - p);
    int hi = B - p;

    if (lo > hi || hi < 2 || lo > B) continue;

    lo = max(lo, 2);
    hi = min(hi, B);

    if (lo > hi) continue;

    // Prebroji proste brojeve u rasponu [lo, hi]
    count += prime_count[hi] - prime_count[lo - 1];
  }

  cout << count << endl;

  return 0;
}

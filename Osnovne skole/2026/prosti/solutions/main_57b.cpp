#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  // Eratostenovo sito
  vector<bool> is_prime(B + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= B; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= B; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Sakupi sve proste brojeve
  vector<int> primes;
  for (int i = 2; i <= B; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  long long count = 0;
  for (int i = 0; i < (int)primes.size(); i++) {
    for (int j = i + 1; j < (int)primes.size(); j++) {
      int s = primes[i] + primes[j];
      if (s >= A && s <= B) {
        count++;
      }
      if (s > B) break;
    }
  }

  cout << count << endl;

  return 0;
}

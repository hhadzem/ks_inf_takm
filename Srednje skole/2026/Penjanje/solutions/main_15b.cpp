#include <iostream>
#include <map>

using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, int> freq;
  for (int i = 0; i < N; i++) {
    int x, y, s;
    cin >> x >> y >> s;
    freq[y]++;
  }

  int maxFreq = 0;
  for (auto &[y, cnt] : freq) {
    maxFreq = max(maxFreq, cnt);
  }

  if (maxFreq == N) {
    cout << -1 << endl;
  } else {
    cout << maxFreq + 1 << endl;
  }

  return 0;
}

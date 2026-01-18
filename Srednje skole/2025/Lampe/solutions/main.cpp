#include <iostream>

using namespace std;
int N, A[200005], S[200005], T[200005];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) {
    if (A[i] == 0) S[i] = S[i - 1] + 1;
    else S[i] = S[i - 1];
  }
  for (int i = N; i >= 0; i--) {
    if (A[i] == 1) T[i] = T[i + 1] + 1;
    else T[i] = T[i + 1];
  }
  int ans = 1000000000;
  for (int i = 0; i <= N; i++) {
    ans = min(ans, S[i] + T[i + 1]);
  }
  cout << ans << endl;
}
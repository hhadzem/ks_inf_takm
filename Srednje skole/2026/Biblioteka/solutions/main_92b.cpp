#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;

  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  const int INF = 1<<29;

  // dp[k] = min broj mjesta za ubaciti B[0..j] tako da B[j] ide u prazninu k
  vector<int> dp(N + 1, INF);
  vector<int> ndp(N + 1, INF);

  // Baza: j = 0
  for (int k = 0; k <= N; k++) {
    bool lijevo_ok = (k == 0) || (A[k - 1] <= B[0]);
    bool desno_ok = (k == N) || (B[0] <= A[k]);
    if (lijevo_ok && desno_ok) {
      dp[k] = 1;
    }
  }

  // Popuni DP za j = 1 do M-1
  for (int j = 1; j < M; j++) {
    for (int k = 0; k <= N; k++) {
      ndp[k] = INF;
    }

    int prefix_min = INF;

    for (int k = 0; k <= N; k++) {
      bool lijevo_ok = (k == 0) || (A[k - 1] <= B[j]);
      bool desno_ok = (k == N) || (B[j] <= A[k]);

      if (lijevo_ok && desno_ok) {
        // Opcija 1: B[j-1] je takodje bio u praznini k (isto mjesto)
        if (dp[k] < INF) {
          ndp[k] = min(ndp[k], dp[k]);
        }
        // Opcija 2: B[j-1] je bio u nekoj praznini k' < k (novo mjesto)
        if (prefix_min < INF) {
          ndp[k] = min(ndp[k], prefix_min + 1);
        }
      }

      prefix_min = min(prefix_min, dp[k]);
    }

    dp = ndp;
  }

  int ans = INF;
  for (int k = 0; k <= N; k++) {
    ans = min(ans, dp[k]);
  }

  cout << ans << endl;

  return 0;
}

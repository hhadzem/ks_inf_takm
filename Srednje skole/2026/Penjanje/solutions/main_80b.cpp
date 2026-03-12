#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool> visited(2000, false);

bool dfs(const vector<vector<int>> &adj,
         vector<int> &right_pair,
         vector<int> &left_pair,
         int u) {
  visited[u] = true;
  for (auto &v : adj[u]) {
    if (left_pair[v] == -1 ||
        (!visited[left_pair[v]] && dfs(adj, right_pair, left_pair, left_pair[v]))) {
      left_pair[v] = u;
      right_pair[u] = v;
      return true;
    }
  }
  return false;
}

int kuhn(int N, int M, const vector<vector<int>> &adj) {
  vector<int> right_pair(N, -1), left_pair(M, -1);
  for (int i = 0; i < N; ++i) {
    if (right_pair[i] != -1) continue;
    visited.assign(2000, false);
    dfs(adj, right_pair, left_pair, i);
  }
  int unmatched = 0;
  for (int i = 0; i < N; ++i) {
    if (right_pair[i] == -1) ++unmatched;
  }
  return unmatched;
}

int main() {
  int N;
  cin >> N;

  vector<int> X(N), Y(N), S(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> S[i];
  }

  vector<vector<bool>> adj(N, vector<bool>(N, false));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      int dx = abs(X[i] - X[j]);
      int dy = abs(Y[i] - Y[j]);
      int max_dist = max(dx, dy);
      int max_friction = max(S[i], S[j]);

      if (Y[i] < Y[j] && max_dist <= max_friction) {
        adj[i][j] = true;
      }
    }
  }

  if (N <= 20) {
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (adj[i][k] && adj[k][j]) {
            adj[i][j] = true;
          }
        }
      }
    }
  }

  vector<vector<int>> bipartite_adj(N);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i != j && adj[i][j]) {
        bipartite_adj[i].push_back(j);
      }
    }
  }

  int unmatched = kuhn(N, N, bipartite_adj);
  int matching_size = N - unmatched;

  int answer;
  if (matching_size == 0) {
    answer = -1;
  } else {
    answer = N - matching_size + 1;
  }

  cout << answer << endl;

  return 0;
}

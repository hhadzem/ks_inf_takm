#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 25;

vector<vector<bool>> adj(MAXN, vector<bool>(MAXN, false));
vector<int> right_pair(MAXN, -1), left_pair(MAXN, -1);
vector<bool> visited(MAXN, false);
vector<vector<int>> bipartite_adj(MAXN);

bool dfs(int u) {
  visited[u] = true;
  for (int v : bipartite_adj[u]) {
    if (left_pair[v] == -1 ||
        (!visited[left_pair[v]] && dfs(left_pair[v]))) {
      left_pair[v] = u;
      right_pair[u] = v;
      return true;
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  vector<int> X(MAXN), Y(MAXN), S(MAXN);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> S[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
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

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (adj[i][k] && adj[k][j]) {
          adj[i][j] = true;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i != j && adj[i][j]) {
        bipartite_adj[i].push_back(j);
      }
    }
  }

  int matching = 0;
  for (int i = 0; i < N; i++) {
    visited.assign(MAXN, false);
    if (dfs(i)) matching++;
  }

  if (matching == 0) {
    cout << -1 << endl;
  } else {
    cout << N - matching + 1 << endl;
  }

  return 0;
}

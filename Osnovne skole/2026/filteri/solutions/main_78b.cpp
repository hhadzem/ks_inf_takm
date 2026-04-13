#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W, A, B;

  cin >> H >> W;

  vector <vector<int>> mat_a(H + 2, vector<int>(W + 2));
  vector <vector<bool>> mat_b(H + 2, vector<bool>(W + 2, false));

  cin >> A;

  int r1, c1, r2, c2;

  for (int i = 0; i < A; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    mat_a[r1][c1]++;
    mat_a[r2 + 1][c1]--;
    mat_a[r1][c2 + 1]--;
    mat_a[r2 + 1][c2 + 1]++;
  }

  cin >> B;

  for (int i = 0; i < B; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    for (int r = r1; r <= r2; r++) {
      for (int c = c1; c <= c2; c++) {
        mat_b[r][c] = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i > 0) {
        mat_a[i][j] += mat_a[i - 1][j];
      }
      if (j > 0) {
        mat_a[i][j] += mat_a[i][j - 1];
      }
      if (i > 0 && j > 0) {
        mat_a[i][j] -= mat_a[i - 1][j - 1];
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(mat_a[i][j] && mat_b[i][j]) {
        cout << "#";
      } else if(mat_a[i][j] || mat_b[i][j]) {
        cout << "/";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }


  return 0;
}

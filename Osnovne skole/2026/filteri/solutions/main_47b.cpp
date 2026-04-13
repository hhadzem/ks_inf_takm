#include <iostream>

using namespace std;

int mat_a[1010][1010];
int mat_b[1010][1010];

int main() {
  int H, W, A, B;

  cin >> H >> W;

  cin >> A;

  int r1, c1, r2, c2;

  for (int i = 0; i < A; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    for (int r = r1; r <= r2; r++) {
      for (int c = c1; c <= c2; c++) {
        mat_a[r][c] ++;
      }
    }
  }

  cin >> B;

  for (int i = 0; i < B; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    for (int r = r1; r <= r2; r++) {
      for (int c = c1; c <= c2; c++) {
        mat_b[r][c] ++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(mat_a[i][j] && mat_b[i][j]) {
        cout << "#";
      } else if(mat_a[i][j] || mat_b[i][j]) {
        cout << "/";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }


  return 0;
}

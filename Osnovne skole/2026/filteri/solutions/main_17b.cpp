#include <iostream>

using namespace std;

int mat[1010][1010];

int main() {
  int H, W, A, B;

  cin >> H >> W;

  cin >> A;

  int r1, c1, r2, c2;

  for (int i = 0; i < A; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    mat[r1][c1] = 1;
  }

  cin >> B;

  for (int i = 0; i < B; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    if(mat[r1][c1] == 1 || mat[r1][c1] == 3) {
      mat[r1][c1] = 3;
    } else {
      mat[r1][c1] = 2;
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(mat[i][j] == 3) {
        cout << "#";
      } else if(mat[i][j] == 1 || mat[i][j] == 2) {
        cout << "/";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }


  return 0;
}

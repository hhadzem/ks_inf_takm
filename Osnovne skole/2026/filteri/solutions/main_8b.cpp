#include <iostream>

using namespace std;

bool mat[1010][1010];

int main() {
  int H, W, A, B;

  cin >> H >> W;

  cin >> A;

  int r1, c1, r2, c2;

  for (int i = 0; i < A; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    mat[r1][c1] = true;
  }

  cin >> B;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(mat[i][j]) {
        cout << "/";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }


  return 0;
}

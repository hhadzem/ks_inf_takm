#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W, A, B;

  cin >> H >> W;

  vector <vector<int>> filteri_A(H + 2, vector<int>(W + 2)), filteri_B(H + 2, vector<int>(W + 2));

  cin >> A;

  int r1, c1, r2, c2;

  for (int i = 0; i < A; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    filteri_A[r1][c1]++;
    filteri_A[r2 + 1][c1]--;
    filteri_A[r1][c2 + 1]--;
    filteri_A[r2 + 1][c2 + 1]++;
  }

  cin >> B;

  for (int i = 0; i < B; i++) {
    cin >> r1 >> c1 >> r2 >> c2;

    filteri_B[r1][c1]++;
    filteri_B[r2 + 1][c1]--;
    filteri_B[r1][c2 + 1]--;
    filteri_B[r2 + 1][c2 + 1]++;
  }


  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i > 0) {
        filteri_A[i][j] += filteri_A[i - 1][j];
        filteri_B[i][j] += filteri_B[i - 1][j];
      }
      if (j > 0) {
        filteri_A[i][j] += filteri_A[i][j - 1];
        filteri_B[i][j] += filteri_B[i][j - 1];
      }
      if (i > 0 && j > 0) {
        filteri_A[i][j] -= filteri_A[i - 1][j - 1];
        filteri_B[i][j] -= filteri_B[i - 1][j - 1];
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(filteri_A[i][j] > 0 && filteri_B[i][j] > 0) {
        cout << "#";
      } else if (filteri_A[i][j] > 0 || filteri_B[i][j] > 0) {
        cout << "/";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }


  return 0;
}

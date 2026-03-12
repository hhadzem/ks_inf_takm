#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, A;
  vector <int> B(10);

  cin >> N >> A >> M;
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  if(A <= B[0]) {
    cout << 1 << endl;
    return 0;
  }

  if(A >= B[M - 1]) {
    cout << 1 << endl;
    return 0;
  }

  cout << 2 << endl;
  return 0;
}

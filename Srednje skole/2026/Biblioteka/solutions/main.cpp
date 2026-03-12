#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;

  // Učitaj broj postojećih knjiga i njihove visine
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // Učitaj broj novih knjiga i njihove visine
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  // Two pointer pristup
  int i = 0;  // pointer za postojeće knjige A
  int j = 0;  // pointer za nove knjige B
  int br = 0; // brojač mjesta

  // Prolazimo kroz postojeće knjige
  while (i < N && j < M) {
    // Ako je trenutna postojeća knjiga A[i] veća od nove knjige B[j],
    // to znači da B[j] treba ići prije A[i]
    if (A[i] > B[j]) {
      br++; // Ovo je novo mjesto za ubacivanje, dodajemo knjige na poziciju prije A[i]

      // Ubaci sve nove knjige koje mogu ići na ovu poziciju
      // (sve koje su manje ili jednake A[i])
      while (j < M && A[i] >= B[j]) {
        j++;
      }
    } else {
      // A[i] <= B[j], pa nastavljamo sa sljedećom postojećom knjigom
      i++;
    }
  }

  // Ako su preostale nove knjige, sve idu na kraj police
  if (j < M) {
    br++;
  }

  cout << br << endl;

  return 0;
}

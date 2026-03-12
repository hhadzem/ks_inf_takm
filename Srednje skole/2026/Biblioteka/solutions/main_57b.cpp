#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, M;

  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++)
  {
    cin >> B[i];
  }

  int ans = M;

  // Probaj sve moguce particije niza B na uzastopne grupe
  // Bitmaska odredjuje gdje se dijeli: bit i znaci podjela izmedju B[i] i B[i+1]
  for (int mask = 0; mask < (1 << (M - 1)); mask++)
  {
    // Napravi grupe
    vector<pair<int, int>> grupe;
    int start = 0;
    for (int i = 0; i < M - 1; i++)
    {
      if (mask & (1 << i))
      {
        grupe.push_back({start, i});
        start = i + 1;
      }
    }
    grupe.push_back({start, M - 1});

    int br_grupa = grupe.size();
    int gap = 0;
    bool validno = true;

    // Greedy dodijeli svaku grupu najranijem validnom mjestu
    for (int g = 0; g < br_grupa; g++)
    {
      int l = grupe[g].first;
      int r = grupe[g].second;
      bool nadjeno = false;

      while (gap <= N)
      {
        bool lijevo_ok = (gap == 0) || (A[gap - 1] <= B[l]);
        bool desno_ok = (gap == N) || (B[r] <= A[gap]);
        if (lijevo_ok && desno_ok)
        {
          nadjeno = true;
          break;
        }
        gap++;
      }

      if (!nadjeno)
      {
        validno = false;
        break;
      }
      gap++;
    }

    if (validno)
    {
      ans = min(ans, br_grupa);
    }
  }

  cout << ans << endl;

  return 0;
}

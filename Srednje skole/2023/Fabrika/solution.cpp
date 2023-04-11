#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > mat(n, vector <int>(m));
    vector <int> ispis(m, 0);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			cin  >> mat[i][j];
			if(i == 0)
				ispis[i] = mat[i][j];
			ispis[j] = max(ispis[j], mat[i][j]);
		}

	for(int i = 0; i < m; i++)
		cout << ispis[i] << " ";
    return 0;
}

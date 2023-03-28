#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, k, l;

    cin >> m >> n >> k >> l;
    k--;
    l--;

    vector<vector<char> > mapa(m, vector<char>(n));
    vector<vector<bool> > posjecena(m, vector<bool>(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> mapa[i][j];

    int br = 0;
    bool izasao = false;

    while(!izasao && !posjecena[k][l]) {
        posjecena[k][l] = true;
        br++;
		
        if(mapa[k][l] == 'V') k++;
        else if(mapa[k][l] == '^') k--;
        else if(mapa[k][l] == '>') l++;
        else l--;

        if(k < 0 || k >= m || l < 0 || l >= n) izasao = true;
    }

	cout << (izasao ? "I " : "O ") << br << endl;
    return 0;
}

#include <iostream>
#define N 3
using namespace std;

int main() {
    int mat[N][N], magicni_zbir = 0;
	bool magicni = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];
		magicni_zbir += mat[i][i];
	}
	
	for(int i = 0; i < N; i++) {
		int red = 0, kolona = 0;
		for(int j = 0; j < N; j++) {
			red += mat[i][j];
			kolona += mat[j][i];
		}
		magicni &= (red == magicni_zbir);
		magicni &= (kolona == magicni_zbir);
	}
    
	cout << (magicni ? magicni_zbir : -1) << endl;
    return 0;
}

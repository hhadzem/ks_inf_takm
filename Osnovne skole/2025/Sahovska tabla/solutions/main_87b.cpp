#include <iostream>

using namespace std;

int main() {
	int h, w, m, n;
	char c[2];

	cin >> h >> w >> m >> n >> c[0] >> c[1];

	for(int i=0;i<h*m;i++) {
		for(int j=0;j<w*n;j++) {
			if((i/m+j/n)%2) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}

	return 0;
}

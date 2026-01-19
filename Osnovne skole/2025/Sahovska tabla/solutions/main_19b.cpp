#include <iostream>

using namespace std;

int main() {
	int h, w, m, n;
	char c[2];

	cin >> h >> w >> m >> n >> c[0] >> c[1];

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cout << c[(i+j)%2] << c[(i+j)%2];
		}
		cout << endl;
		for(int j=0;j<n;j++) {
			cout << c[(i+j)%2] << c[(i+j)%2];
		}
		cout << endl;
	}

	return 0;
}

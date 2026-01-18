#include <iostream>

using namespace std;

int main() {
	long long n, k, p;

	cin >> n >> k >> p;

	// Switch case for p
	switch(p) {
		case 1:
			cout << n-k;
			break;
		case 2:
			cout << n-k << endl;
			cout << n-k-k;
			break;
		default:
			cout << n-k << endl;
			cout << n-k-k << endl;
			cout << n-k-k-k;
	}

	return 0;
}

#include <iostream>

using namespace std;

int main() {
	int n, k, p;

	cin >> n >> k >> p;

	if(p == 1) {
		cout << n-k;
	} else {
		cout << n-k << endl;
		cout << n-k-k;
	}

	return 0;
}

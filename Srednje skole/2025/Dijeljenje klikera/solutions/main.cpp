#include <iostream>

using namespace std;

int main() {
	long long n, k, p;

	cin >> n >> k >> p;

	for(int i=0;i<p;i++) {
		n = n - k;
		cout << n << '\n';
	}

	return 0;
}

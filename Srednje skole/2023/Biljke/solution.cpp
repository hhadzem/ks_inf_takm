#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

    int m, n;

    cin >> m >> n;

    vector <int> vb(m), a(n), b(n), c(n);

	for(int i = 0; i < m; i++) cin >> vb[i];
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    long long min_cijena = -1, tc;
    int bitmask = 0, bmc, obm;
    vector <bool> osvjetljena(m);
    bool ok;

    while(bitmask < (1<<n)) {
        for(int i=0;i<m;i++) osvjetljena[i] = 0;
        bmc = bitmask;
        tc = 0;

        for(int i=0;i<n;i++) {
            if(bmc%2) {
                for(int j=0;j<m;j++)
                    if(vb[j] >= a[i] && vb[j] <= b[i]) osvjetljena[j] = true;
                tc += c[i];
            }
            bmc /= 2;
        }
		
        ok = true;
        for(int i = 0; i < m; i++) 
			ok &= osvjetljena[i];

        if(ok && (min_cijena > tc || min_cijena == -1)) {
            min_cijena = tc;
            obm = bitmask;
        }

        bitmask++;
    }

    cout << min_cijena << '\n';

    if(min_cijena == -1) return 0;

    for(int i = 0; i < n; i++) {
		cout << obm % 2;
		obm /= 2;
    }

    return 0;
}

/*
	HONI 2012/13, 1. kolo, zadatak SNAGA
	Autor: Adrian Satja Kurdija

	Za svaki broj K od 1 do 100 izracunamo
	snagu i potom vidimo koliko brojeva
	izmedju A i B ima upravo K za sljedbenika
	(sto znaci da im je snaga za jedan veca).
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long A, B, rjesenje = 0;
	cin >> A >> B;

	// NZV = lcm(1, 2, ..., K-1)
	long long NZV = 1;

	int snaga[100];
	snaga[2] = 1;
	for (int K = 2; K < 100; K++)
	{
		// Izracunaj snaga[K]
		for (int i = 2; i < K; i++) {
			if (K % i != 0) {
				snaga[K] = snaga[i] + 1;
				break;
			}
		}

		// Koliko brojeva izmedju A i B se preslikava u K?
		// To su svi djeljivi sa NZV(1, ..., K-1) ali ne i
		// sa NZV(1, ..., K-1, K). Potonji NZV razlikuje se
		// od prethodnog tek ako je K potencija prostog broja.
		long long novi_NZV = NZV;
		vector<int> prosti_djelitelji_K;
		for (int p = 2, k = K; k > 1; p++) {
			if (k % p == 0) {
				prosti_djelitelji_K.push_back(p);
				while (k % p == 0) {
					k /= p;
				}
			}
		}
		if ((int)prosti_djelitelji_K.size() == 1) {
			novi_NZV *= prosti_djelitelji_K[0];
		}
		
		rjesenje += (snaga[K] + 1) * (B/NZV - (A-1)/NZV);

		// Cim novi_NZV postane veci od B
		// (ili overflowa), prekidamo pricu.
		if (novi_NZV > B || novi_NZV < 0) break;
		rjesenje -= (snaga[K] + 1) * (B/novi_NZV - (A-1)/novi_NZV);
		
		NZV = novi_NZV;
	}
	cout << rjesenje << endl;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int broj_clanova;
    cin >> broj_clanova;

    vector<int> brojevi(broj_clanova);
    for (int i = 0; i < broj_clanova; i++) 
        cin >> brojevi[i];
   
    int max_broj = 0;
    for (int gcd = 2; gcd < 1000; gcd++) {
        int broj_dijeljivih = 0;
        for (int i = 0; i < broj_clanova; i++)
            if (brojevi[i] % gcd == 0)
                broj_dijeljivih++;
			
        if (broj_dijeljivih > max_broj)
            max_broj = broj_dijeljivih;
    }

    cout << max_broj << endl;

    return 0;
}
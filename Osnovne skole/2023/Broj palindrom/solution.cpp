#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s; cin >> s;

    vector <int> br_cifara(10);
    for(int i = 0; i < s.length(); i++)
        br_cifara[s[i]-'0']++;

    int br_neparnih = 0, indeks_neparne;

    for(int i = 0; i < 10; i++) {
        if(br_cifara[i] % 2) {
            br_neparnih++;
            indeks_neparne = i;
        }
    }
	
    int br_nenultih = s.length() - br_cifara[0];
    if(br_neparnih > 1 || (s.length() > 1 && br_nenultih < 2) ) {
        cout << "Nemoguce!";
        return 0;
    }

    string ispis;

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < br_cifara[i]/2; j++)
            ispis += '0' + i;

    for(int i = 0; i < ispis.length(); i++) {
        if(ispis[i] != '0') {
            swap(ispis[i], ispis[0]);
            break;
        }
    }

    string kopija_ispisa = ispis;
    reverse(kopija_ispisa.begin(), kopija_ispisa.end());

	cout << ispis + (br_neparnih ? char('0' + indeks_neparne) + kopija_ispisa: kopija_ispisa) << endl;
    return 0;
}

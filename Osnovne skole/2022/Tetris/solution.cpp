#include <iostream>

using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int broj_tacaka = 0;

    for(int i=0;i<3;i++) {
        if(s1[i] == '.') broj_tacaka ++;
        if(s2[i] == '.') broj_tacaka ++;
    }

    if(broj_tacaka < 4) {
        cout << "NE";
        return 0;
    }

    if(broj_tacaka > 4) {
        cout << "DA";
        return 0;
    }

    /// Sada je broj tacaka sigurno tacno 4, odnosno broj taraba tacno 2

    /// Jedine kombinacije pozicija koje ne odgovaraju su sljedecih oblika (plus njihove rotacije i izokretanja)

    /*
    .#.
    .#.

    i

    .#.
    #..
    */

    /// Ako su obje tarabe u istom redu onda je sigurno moguce smjestiti tetromino

    if(s1 == "..." || s2 == "...") {
        cout << "DA";
        return 0;
    }

    /// Sada je dovoljno samo se pobrinuti da nema taraba u srednjoj koloni

    if(s1[1] == '.' && s2[1] == '.') {
        cout << "DA";
        return 0;
    }

    /// Preostale moguænosti su oblika opisanog iznad, tako da znamo da je nemoguæe postaviti tetromino

    cout << "NE";

    return 0;
}

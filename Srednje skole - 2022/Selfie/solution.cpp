#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 510
int sirina, visina;
int stanica_start_x, stanica_start_y;
int stanica_kraj_x, stanica_kraj_y;

ifstream in("in.txt");
ofstream out("out.txt");

#define postavi_ret \
if (nova_vrijednost + ocjene[x][y] > ret || !ret_postavljen) { \
    ret_postavljen = true; \
    ret = nova_vrijednost + ocjene[x][y]; \
}

int rjesenjeRekurzivno(int ocjene[MAX_SIZE][MAX_SIZE], int x=sirina-1, int y=visina-1) {
    int ret = ocjene[x][y];
    bool ret_postavljen = false;
    if (x != 0) {
        int nova_vrijednost = rjesenjeRekurzivno(ocjene, x - 1, y);
        postavi_ret;
    }
    if (y != 0) {
        int nova_vrijednost = rjesenjeRekurzivno(ocjene, x, y - 1);
        postavi_ret;
    }
    if (x == stanica_kraj_x && y == stanica_kraj_y) {
        int nova_vrijednost = rjesenjeRekurzivno(ocjene, stanica_start_x, stanica_start_y);
        postavi_ret;
    }
    return ret;
}

int rjesenjeDP(int ocjene[MAX_SIZE][MAX_SIZE]) {
    auto najbolje = new int[sirina][MAX_SIZE];
    for (int x=0; x<sirina; x++) {
        for (int y=0; y<visina; y++) {
            int ret = ocjene[x][y];
            bool ret_postavljen = false;
            if (x > 0) {
                int nova_vrijednost = najbolje[x-1][y];
                postavi_ret;
            }
            if (y > 0) {
                int nova_vrijednost = najbolje[x][y-1];
                postavi_ret;
            }
            if (x == stanica_kraj_x && y == stanica_kraj_y) {
                int nova_vrijednost = najbolje[stanica_start_x][stanica_start_y];
                postavi_ret;
            }
            najbolje[x][y] = ret;
        }
    }
    int rezultat = najbolje[sirina-1][visina-1];
    delete[] najbolje;
    return rezultat;
}

int main() {
    cin >> sirina >> visina;

    int ocjene[MAX_SIZE][MAX_SIZE];

    for (int i=0; i<visina; i++) {
        for (int j=0; j<sirina; j++) {
            cin >> ocjene[j][i];
        }
    }
    cin >> stanica_start_x >> stanica_start_y;
    cin >> stanica_kraj_x >> stanica_kraj_y;
    cout << rjesenjeDP(ocjene);
}
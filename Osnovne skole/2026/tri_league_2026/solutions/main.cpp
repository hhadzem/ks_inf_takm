#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Mec {
    string timA;  // domacin
    string timB;
    string timC;
    int a = 0;
    int b = 0;
    int c = 0;
};

istream& operator>>(istream& ulaz, Mec& mec) {
    string crta1, crta2, dvotacka, crta3, crta4;
    ulaz >> mec.timA >> crta1 >> mec.timB >> crta2 >> mec.timC >> dvotacka >> mec.a >> crta3 >> mec.b >> crta4 >> mec.c;
    return ulaz;
}

ostream& operator<<(ostream& izlaz, const Mec& mec) {
    izlaz << mec.timA << " - " << mec.timB << " - " << mec.timC << " : " << mec.a << " - " << mec.b << " - " << mec.c;
    return izlaz;
}

struct StatistikaTima {
    string ime;
    int P = 0;  // liga bodovi
    int F = 0;  // postignuti fragovi
    int A = 0;  // primljeni fragovi
    int D = 0;  // F - A
    int W = 0;  // broj strogih prvih mjesta
    int H = 0;  // fragovi postignuti kao domacin
    int X = 0;  // ciste pobjede
    int brojDomacihUtakmica = 0;
};

static int uporediProsjekDomacihFragova(const StatistikaTima& lijevi, const StatistikaTima& desni) {
    // Ako tim nema nijednu domacu utakmicu, njegov prosjek domacih fragova je 0.
    if (lijevi.brojDomacihUtakmica == 0 && desni.brojDomacihUtakmica == 0) return 0;
    if (lijevi.brojDomacihUtakmica == 0) return -1;
    if (desni.brojDomacihUtakmica == 0) return 1;
    int lijevaStrana = lijevi.H * desni.brojDomacihUtakmica;
    int desnaStrana = desni.H * lijevi.brojDomacihUtakmica;
    if (lijevaStrana < desnaStrana) return -1;
    if (lijevaStrana > desnaStrana) return 1;
    return 0;
}

static bool istiKriterijiRangiranja(const StatistikaTima& lijevi, const StatistikaTima& desni) {
    if (lijevi.P != desni.P) return false;
    if (lijevi.D != desni.D) return false;
    if (lijevi.F != desni.F) return false;
    if (lijevi.W != desni.W) return false;
    if (lijevi.X != desni.X) return false;
    if ((lijevi.F - lijevi.H) != (desni.F - desni.H)) return false;
    return uporediProsjekDomacihFragova(lijevi, desni) == 0;
}

static bool boljiPoKriterijimaRangiranja(const StatistikaTima& lijevi, const StatistikaTima& desni) {
    if (lijevi.P != desni.P) return lijevi.P > desni.P;
    if (lijevi.D != desni.D) return lijevi.D > desni.D;
    if (lijevi.F != desni.F) return lijevi.F > desni.F;
    if (lijevi.W != desni.W) return lijevi.W > desni.W;
    if (lijevi.X != desni.X) return lijevi.X > desni.X;
    int gostujucaSnagaLijevog = lijevi.F - lijevi.H;
    int gostujucaSnagaDesnog = desni.F - desni.H;
    if (gostujucaSnagaLijevog != gostujucaSnagaDesnog) return gostujucaSnagaLijevog > gostujucaSnagaDesnog;
    int poredenjeProsjeka = uporediProsjekDomacihFragova(lijevi, desni);
    if (poredenjeProsjeka != 0) return poredenjeProsjeka < 0;
    return lijevi.ime < desni.ime;  // samo da poredak bude deterministicki
}

void primijeniMec(vector<StatistikaTima>& timovi, const map<string, int>& indeksiTimova, const Mec& mec) {
    int indeksA = indeksiTimova.at(mec.timA);
    int indeksB = indeksiTimova.at(mec.timB);
    int indeksC = indeksiTimova.at(mec.timC);

    int rezultati[3] = {mec.a, mec.b, mec.c};
    int indeksi[3] = {indeksA, indeksB, indeksC};

    timovi[indeksA].F += mec.a;
    timovi[indeksB].F += mec.b;
    timovi[indeksC].F += mec.c;

    timovi[indeksA].A += mec.b + mec.c;
    timovi[indeksB].A += mec.a + mec.c;
    timovi[indeksC].A += mec.a + mec.b;

    timovi[indeksA].D = timovi[indeksA].F - timovi[indeksA].A;
    timovi[indeksB].D = timovi[indeksB].F - timovi[indeksB].A;
    timovi[indeksC].D = timovi[indeksC].F - timovi[indeksC].A;

    timovi[indeksA].H += mec.a;
    timovi[indeksA].brojDomacihUtakmica++;

    vector<pair<int, int>> poredak = {{rezultati[0], 0}, {rezultati[1], 1}, {rezultati[2], 2}};
    sort(poredak.begin(), poredak.end(), greater<pair<int, int>>());

    const int maksimum = poredak[0].first;
    const int srednji = poredak[1].first;
    const int minimum = poredak[2].first;

    if (maksimum == srednji && srednji == minimum) {
        timovi[indeksi[0]].P += 2;
        timovi[indeksi[1]].P += 2;
        timovi[indeksi[2]].P += 2;
    } else if (maksimum == srednji) {
        timovi[indeksi[poredak[0].second]].P += 3;
        timovi[indeksi[poredak[1].second]].P += 3;
    } else if (srednji == minimum) {
        timovi[indeksi[poredak[0].second]].P += 4;
        timovi[indeksi[poredak[1].second]].P += 1;
        timovi[indeksi[poredak[2].second]].P += 1;
    } else {
        timovi[indeksi[poredak[0].second]].P += 4;
        timovi[indeksi[poredak[1].second]].P += 2;
    }

    if (maksimum > srednji) {
        int lokalniPobjednik = poredak[0].second;
        StatistikaTima& pobjednik = timovi[indeksi[lokalniPobjednik]];
        pobjednik.W++;
        if (maksimum >= 2 * minimum) pobjednik.X++;
    }
}

vector<StatistikaTima> izracunajPoredak(const vector<string>& imenaTimova, const vector<Mec>& mecevi) {
    map<string, int> indeksiTimova;
    vector<StatistikaTima> timovi;
    timovi.reserve(imenaTimova.size());
    for (int i = 0; i < static_cast<int>(imenaTimova.size()); i++) {
        indeksiTimova[imenaTimova[i]] = i;
        StatistikaTima statistika;
        statistika.ime = imenaTimova[i];
        timovi.push_back(statistika);
    }
    for (const Mec& mec : mecevi) primijeniMec(timovi, indeksiTimova, mec);
    sort(timovi.begin(), timovi.end(), boljiPoKriterijimaRangiranja);
    return timovi;
}

bool trebaRazigravanje(const vector<StatistikaTima>& poredaniTimovi) {
    for (int i = 1; i < static_cast<int>(poredaniTimovi.size()); i++) {
        if (istiKriterijiRangiranja(poredaniTimovi[i - 1], poredaniTimovi[i])) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int brojTimova = 0;
    cin >> brojTimova;
    vector<string> imenaTimova(brojTimova);
    for (int i = 0; i < brojTimova; i++) cin >> imenaTimova[i];

    int brojUtakmica = 0;
    cin >> brojUtakmica;
    vector<Mec> mecevi(brojUtakmica);
    for (int i = 0; i < brojUtakmica; i++) cin >> mecevi[i];

    vector<StatistikaTima> poredak = izracunajPoredak(imenaTimova, mecevi);
    if (trebaRazigravanje(poredak)) {
        cout << "Potrebno je razigravanje!\n";
    } else {
        for (const StatistikaTima& tim : poredak) {
            cout << tim.ime << " " << tim.P << "\n";
        }
    }
    return 0;
}

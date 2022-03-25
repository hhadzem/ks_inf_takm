#include <iostream>
using namespace std;

// vraca koja je ovo minuta po redu u ovom danu
int minuta_po_redu(int sat, int minuta) {
  return sat * 60 + minuta;
}

int main() {
  // Krecemo s pretpostavkom da su sve minute slobodne.
  // U danu imamo 24 * 60 minuta
  int broj_slobodnih_minuta = 24 * 60;
  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    int start_sati, start_minute, stop_sati, stop_minute;
    cin >> start_sati >> start_minute >> stop_sati >> stop_minute;
    int pocetna_minuta = minuta_po_redu(start_sati, start_minute);
    int zadnja_minuta = minuta_po_redu(stop_sati, stop_minute);
    // oduzeti od ukupnog broja minuta trajanje ovog termina
    broj_slobodnih_minuta -= zadnja_minuta - pocetna_minuta;
  }
  cout << broj_slobodnih_minuta;
}
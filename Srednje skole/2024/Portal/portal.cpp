#include <iostream>
 
using namespace std;
 
int main() {
    int n, niz[100];
    cin >> n;
     
    for(int i = 0; i < n; i++) {
        cin >> niz[i];
        if(niz[i] % 2 + i % 2 != 1) {
            cout << "Portal ostaje zatvoren";
            return 0;
        }
    }
     
    cout << "Portal se otvara";
    return 0;
}
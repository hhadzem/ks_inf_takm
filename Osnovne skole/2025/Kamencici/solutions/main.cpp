#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int brojac = 0;

    while(a > b) {
        a = a / 2;
        brojac++;
    }

    cout << brojac + (b - a);
    
    return 0;
}
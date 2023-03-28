#include <iostream>

using namespace std;

int main() {

    int a1, a2, b1, b2, c1, c2;
    int A, B, C;

    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> A >> B >> C;

    for(int i=0;i<40*40*40;i++) {
        if(A == a1 && B == b1 && C == c1) {
            cout << i;
            return 0;
        }

        A++;
        A %= a1 + a2;
        B++;
        B %= b1 + b2;
        C++;
        C %= c1 + c2;
    }

    cout << -1;

    return 0;
}

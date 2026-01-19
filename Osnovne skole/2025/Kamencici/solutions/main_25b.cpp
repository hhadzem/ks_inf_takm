#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int br = 0;

    while(a != b) {
        a/=2;
        br++;
    }

    cout << br;
    
    return 0;
}
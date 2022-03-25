#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string s;

    cin >> s;

    int ostatak = 0;

    for(int i=0;i<s.length();i++) {
        ostatak *= 10;
        ostatak += s[i]-'0';

        ostatak %= 7;
    }

    if(ostatak == 0) cout << 7;
    else cout << ostatak;

    return 0;
}

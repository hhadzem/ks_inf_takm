#include <iostream>

using namespace std;

bool parnost(int a){
	return a % 2;
}

void to_ascii(string &s) {
	for(int i = 0 ; i < s.length(); i++)
		s[i] += '0';
}

int main() {
    string s; cin >> s;

    for(int i = 0; i < s.length(); i++) s[i] -= '0';

    int c = 0;
    for(int i = 1; i < s.length(); i++) {
		if(parnost(s[i]) == parnost(s[i-1])) {
			c = i;
			break;
		}
    }

    if(c == 0) {
        cout << s;
        return 0;
    }

    string s_veci = s, s_manji = s;

    s_veci[c]++;
    s_manji[c]--;

    for(int i = c + 1; i < s.length(); i++) {
		s_veci[i] = (parnost(s_veci[i-1]) ? 0 : 1);
		s_manji[i] = (parnost(s_manji[i-1] ? 8 : 9);
    }

    if(s[c] == 0) {
		to_ascii(s_veci);
		cout << s_veci;
        return 0;
    }

    if(s[c] == 9) {
		to_ascii(s_manji);
        cout << s_manji;
        return 0;
    }

    int blizi = -1, srednja_cifra;

    for(int i = c + 1; i < s.length(); i++) {
		if(parnost(s[c]) && parnost(i-c))
			srednja_cifra = 5;
		else if(!parnost(s[c]) && parnost(i-c))
			srednja_cifra = 5;
		else
			srednja_cifra = 4;

        if(s[i] < srednja_cifra) {
            blizi = 0;
            break;
        }

        if(s[i] > srednja_cifra) {
            blizi = 1;
            break;
        }
    }

	to_ascii(s_manji); to_ascii(s_veci);

    if(blizi == 0) 
        cout << s_manji;
    else if(blizi == 1)
        cout << s_veci;
    else 
        cout << s_manji << ' ' << s_veci;

    return 0;
}

#include<iostream>
using namespace std;
int main() {
    string s; cin >> s;
    bool good = true;
    for(char c : s) 
        if(c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') good = false;
    if(good) cout << "DA"; else cout << "NE";
    return 0;
}
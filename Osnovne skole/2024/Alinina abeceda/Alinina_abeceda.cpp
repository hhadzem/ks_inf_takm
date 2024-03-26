#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string alphabet;
vector<int> val(26);

bool compare(const string &a, const string &b) {
    if(a.length() > b.length()) return !compare(b, a);
    
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == b[i]) continue;

        char AA = 'a';
        if(i == 0) AA = 'A';

        return val[a[i]-AA] < val[b[i]-AA];
    }
    
    if(a.length() == b.length()) return false;

    return true;
}

int main() {
    cin >> alphabet;
    for(int i = 0 ; i < alphabet.length(); i++) {
        char curr = alphabet[i];
        val[curr - 'a'] = i;
    }

    int n; cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin >> words[i];
    
    sort(words.begin(), words.end(), compare);
            
    for(int i = 0 ; i < n; i++)
        cout << words[i] << endl;
    return 0;
}
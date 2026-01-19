#include<iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    if(N % 2 || M % 2) cout << "-1" << endl;
    else cout << N * M / 4 << endl;
    return 0;
}
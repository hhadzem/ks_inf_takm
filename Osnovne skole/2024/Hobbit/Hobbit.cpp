#include<iostream>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    if(N % M == 0) cout << "MOGU"; else cout << "NE MOGU";
    return 0;
}
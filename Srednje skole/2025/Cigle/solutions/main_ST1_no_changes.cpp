#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

int solve(const vector<int> &c, const vector<int> &h) {
    int n = c.size();
    int cnt = 0;
    int max_0 = 0;
    int max_1 = 0;

    for(int i=n-1;i>=0;i--) {
        if(c[i] == 0) {
            if(h[i] >= max_0) {
                max_0 = h[i];
                cnt++;
            }
        } else {
            if(h[i] >= max_1) {
                max_1 = h[i];
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <int> c(n);
    vector <int> h(n);

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    cout << solve(c, h);
    return 0;
}

/*
6
0 1 1 0 0 1
7 8 6 2 3 5

5
*/
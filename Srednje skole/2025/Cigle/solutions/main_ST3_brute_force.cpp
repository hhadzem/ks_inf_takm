#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

int solve(const vector<int> &c_original, const vector<int> &h) {
    vector<int> c(c_original);
    int n = c.size();
    int maxCnt = 0;

    {
        int cnt = 0, max_0 = 0, max_1 = 0;
        for(int i = n - 1; i >= 0; i--) {
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
        if(cnt > maxCnt)
            maxCnt = cnt;
    }

    for(int j = 0; j < n; j++) {
        int cnt = 0;
        int max_0 = 0;
        int max_1 = 0;
        
        c[j] = 1 - c[j];

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
        if(cnt > maxCnt) {
            maxCnt = cnt;
        }
        c[j] = 1 - c[j];
    }
    return maxCnt;
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

    cout << solve(c, h) << endl;    

    return 0;
}

/*
3
0 0 1
2 3 1

3


6
0 0 1 0 0 1
7 8 6 2 3 5

5


10
1 1 1 1 1 1 1 1 1 1
5 8 2 7 5 4 7 2 3 1

7


20
0 1 1 1 0 1 1 0 1 1 0 0 0 1 0 1 0 1 0 0 
5 6 8 1 4 5 7 1 2 5 7 9 8 8 8 3 2 2 1 3 

10


7
0 1 0 1 0 0 0
8 9 6 5 5 4 7

6


4
0 0 1 0
2 3 1 4

3


8
0 0 0 0 1 1 0 0
2 2 3 3 1 1 4 4

5


14
0 0 1 1 0 0 1 1 0 0 0 0 0 0
8 8 9 9 6 6 5 5 5 5 4 4 7 7

9

*/
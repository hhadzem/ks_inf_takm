#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

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

    vector<bool> interesting(n);
    int mx = 0, cntInt = 0;
    for(int i=n-1;i>=0;i--) {
        if(h[i] >= mx) {
            interesting[i] = true;
            mx = h[i];
            cntInt++;
        }
    }

    vector <int> p(n);
    map<int, int> pHist;
    int mxPHist = 0;
    
    mx = 0;
    int mxIndex = -1, secondmx = -1;

    for(int i=n-1;i>=0;i--) {
        if(h[i] < mx && h[i] >= secondmx) {
            p[i] = mxIndex;
            pHist[mxIndex]++;
            mxPHist = max(mxPHist, pHist[mxIndex]);
        }   

        if(h[i] >= mx) {
            secondmx = mx;
            mx = h[i];
            mxIndex = i;
        } else if(h[i] >= secondmx) {
            secondmx = h[i];
        }
    }

    
    cout << cntInt + max(1, mxPHist) << endl;
    

    return 0;
}

/*
10
1 1 1 1 1 1 1 1 1 1
5 8 2 7 5 4 7 2 3 1

7
*/
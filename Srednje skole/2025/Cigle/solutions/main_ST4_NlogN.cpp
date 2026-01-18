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
    vector<int> mxv(2), cntIntv(2);
    vector<vector<int>> maxSuffix(2, vector<int>(n));
    for(int i=n-1;i>=0;i--) {
        maxSuffix[c[i]][i] = mxv[c[i]];

        if(h[i] >= mxv[c[i]]) {
            interesting[i] = true;
            mxv[c[i]] = h[i];
            cntIntv[c[i]]++;
        }
    }


    vector<vector<int>> interestingArray(2);
    for(int i=0;i<n;i++) {
        if(interesting[i]) {
            interestingArray[c[i]].push_back(i);
        }
    }

    vector <int> p(n, -1); // p[i] = j <=> brick i will become interesting if the color of brick j is changed
    map<int, int> pHist;
    
    for(int color = 0; color < 2; color++) {
        int mx = 0;
        int mxIndex = -1, secondmx = -1;

        for(int i=n-1;i>=0;i--) {
            if(c[i] != color) continue;

            if(h[i] < mx && h[i] >= secondmx) {
                p[i] = mxIndex;
                pHist[mxIndex]++;
            }   

            if(h[i] >= mx) {
                secondmx = mx;
                mx = h[i];
                mxIndex = i;
            } else if(h[i] >= secondmx) {
                secondmx = h[i];
            }
        }
    }

    int mxGainDelta = 0;

    for(int i=0;i<n;i++) {
        int gain = 0;
        int loss = 0;

        gain += pHist[i];
        

        // How many interesting bricks will become uninteresting if the color of brick i is changed
        // binary search for the first interesting brick with height less than h[i]
        int l = 0, r = interestingArray[1-c[i]].size();

        while(r - l > 1) {
            int m = (l+r)/2;
            if(h[interestingArray[1-c[i]][m]] < h[i]) {
                l = m;
            } else {
                r = m;
            }
        }

        int firstToLose = l;

        // Binary search for the last interesting brick with position less than i
        l = 0, r = interestingArray[1-c[i]].size();

        while(r - l > 1) {
            int m = (l+r)/2;
            if(interestingArray[1-c[i]][m] < i) {
                l = m;
            } else {
                r = m;
            }
        }

        int lastToLose = l;

        if(firstToLose < int(interestingArray[1-c[i]].size()) && h[interestingArray[1-c[i]][firstToLose]] < h[i] && interestingArray[1-c[i]][firstToLose] < i) {
            loss += lastToLose - firstToLose + 1;
        }

        // Check if the brick i is interesting after the color change
        bool interestingAfterChange = false;
        if(maxSuffix[1-c[i]][i] <= h[i]) {
            interestingAfterChange = true;
        }

        if(interestingAfterChange) {
            gain++;
        }
        if(interesting[i]) {
            loss++;
        }


        mxGainDelta = max(mxGainDelta, gain - loss);
    }
    
    cout << cntIntv[0] + cntIntv[1] + mxGainDelta << endl;

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
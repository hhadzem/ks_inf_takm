#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int INF = 2e9+1;

int solve(const vector<int> &c, const vector<int> &h) {
    int n = c.size();

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
    vector<vector<int>> minInterestingPrefix(2, vector<int>(n, INF));
    vector<int> mnv(2, INF);
    for(int i=0;i<n;i++) {
        minInterestingPrefix[c[i]][i] = mnv[c[i]];

        if(interesting[i]) {
            interestingArray[c[i]].push_back(i);
            mnv[c[i]] = min(mnv[c[i]], h[i]);
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

    vector<int> firstToLose(2);
    vector<int> lastToLose(2);

    for(int i=0;i<n;i++) {
        // How many interesting bricks will become uninteresting if the color of brick i is changed
        if(!interesting[i]) {
            // Cannot gain anything except the brick i itself

            // Check if it will make anything else uninteresting
            if(minInterestingPrefix[1-c[i]][i] <= h[i]) {
                // There's an interesting brick on the left that will become uninteresting, so no gain will be made
                continue;
            }
            
            if(maxSuffix[1-c[i]][i] > h[i]) {
                // i won't become interesting, then the gain will be 0 and there's no need to check further
                continue;
            }

            mxGainDelta = max(mxGainDelta, 1); // gain current brick, lose none
            continue;
        }

        // i is interesting
        
        int gain = 0;
        int loss = 0;

        gain += pHist[i]; // Will only happen if i is interesting

        // How many interesting bricks will become uninteresting if the color of brick i is changed
        // Sliding window per color

        while(firstToLose[1-c[i]] < int(interestingArray[1-c[i]].size()) && h[interestingArray[1-c[i]][firstToLose[1-c[i]]]] >= h[i]) {
            firstToLose[1-c[i]]++;
        }

        while(lastToLose[1-c[i]] < int(interestingArray[1-c[i]].size()) && (lastToLose[1-c[i]] < 0 || interestingArray[1-c[i]][lastToLose[1-c[i]]] < i)) {
            lastToLose[1-c[i]]++;
        }
        lastToLose[1-c[i]]--;

        if(firstToLose[1-c[i]] < int(interestingArray[1-c[i]].size()) && firstToLose[1-c[i]] <= lastToLose[1-c[i]]) {
            loss += lastToLose[1-c[i]] - firstToLose[1-c[i]] + 1;
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
    
    return cntIntv[0] + cntIntv[1] + mxGainDelta;
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
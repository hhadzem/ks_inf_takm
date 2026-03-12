#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<ull> cost(N + 2, 0);
    for (int i = 1; i <= N; i++) cin >> cost[i];

    vector<ull> reach(N + 2, 0);
    vector<int> nxt(N + 2, -1);

    deque<int> dq;

    for (int i = N; i >= 0; i--) {
        int j = i + 1;
        ull vj = cost[j] + reach[j];

        while (!dq.empty() && cost[dq.back()] + reach[dq.back()] > vj)
            dq.pop_back();
        dq.push_back(j);

        while (!dq.empty() && dq.front() > i + K)
            dq.pop_front();

        reach[i] = cost[dq.front()] + reach[dq.front()];
        nxt[i] = dq.front();
    }

    cout << reach[0] << "\n";

    vector<int> path;
    int cur = 0;
    while (cur != N + 1) {
        cur = nxt[cur];
        if (cur != N + 1) path.push_back(cur);
    }

    for (int i = 0; i < (int)path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << "\n";

    return 0;
}

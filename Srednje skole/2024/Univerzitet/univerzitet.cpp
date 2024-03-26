#include <iostream>
#include <vector>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
vector<int> g[N], f(N);
int ans;
int n, k;
  
void dfs(int u, int fa) {
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        f[u] += f[v];
        ans += min(f[v], k-f[v]);
    }
}
  
void solve() 
{
     
    cin >> n >> k;
    k <<= 1;
    for (int i = 0; i < k; i ++ ) {
        int x;
        cin >> x;
        f[x] = 1;
    }
  
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
  
    dfs(1, -1);
    cout << ans << endl;
} 
  
signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
     
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
     
}
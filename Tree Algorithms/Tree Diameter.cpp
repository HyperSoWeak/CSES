#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int int64_t
#define fi first
#define se second
#define max max<int>
#define min min<int>
#define all(a) a.begin(),a.end()
#define sz(a) (signed)a.size()
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
constexpr int IINF = 0x3f3f3f3f;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9+7;
constexpr int MN = 2e5+5;

int n, dia, dp[MN];
vi g[MN];

void dfs(int u, int p) {
    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        dia = max(dia, dp[u] + dp[v] + 1);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n-1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << dia << '\n';
}

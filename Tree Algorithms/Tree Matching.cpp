#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
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
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

int n;
vector<int> g[MN];
int dp[MN][2];

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 0;
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for(int v : g[u]) {
        if(v == p) continue;
        dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
    }
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n-1) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

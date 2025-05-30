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
using tiii = tuple<int,int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

int n;
vector<int> g[MN];
int sz[MN], ans[MN], dis;

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v: g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dis += sz[v];
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p, int dis) {
    ans[u] = dis;
    for (int v: g[u]) {
        if (v == p) continue;
        dfs2(v, u, dis + n - 2*sz[v]);
    }
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    ans[1] = dis;
    dfs2(1, -1, dis);
    rep1(i,1,n) cout << ans[i] << " \n"[i==n];
}

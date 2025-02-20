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
const int MN = 1e5+5;

int n, m, q;
vector<pii> g[MN];

signed main() {
    hyper;
    cin >> n >> m >> q;
    rep(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    // floyd-warshall
    vvi d(n+1, vi(n+1, INF));
    rep1(i,1,n) d[i][i] = 0;
    rep1(i,1,n) for(auto [v, w]: g[i]) d[i][v] = min(d[i][v], w);
    rep1(k,1,n) rep1(i,1,n) rep1(j,1,n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << (d[u][v] == INF ? -1 : d[u][v]) << '\n';
    }
}

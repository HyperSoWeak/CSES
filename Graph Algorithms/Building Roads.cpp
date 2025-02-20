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

int n, m;
vi g[MN];
bool vis[MN];

void dfs(int u) {
    vis[u] = 1;
    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }
}

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi a;
    rep1(i,1,n) {
        if(!vis[i]) {
            a.push_back(i);
            dfs(i);
        }
    }
    cout << sz(a)-1 << '\n';
    rep(i,0,sz(a)-1) cout << a[i] << ' ' << a[i+1] << '\n';
}

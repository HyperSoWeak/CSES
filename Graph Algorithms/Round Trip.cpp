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
int pre[MN];

void dfs(int u, int p) {
    for(int v: g[u]) {
        if(v == p) continue;
        if(pre[v]) {
            vi path;
            path.push_back(v);
            for(int x=u; x!=v; x=pre[x]) path.push_back(x);
            path.push_back(v);
            cout << sz(path) << '\n';
            for(int x: path) cout << x << ' ';
            cout << '\n';
            exit(0);
        }
        pre[v] = u;
        dfs(v,u);
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
    rep1(i,1,n) {
        if(!pre[i]) {
            pre[i] = i;
            dfs(i,i);
        }
    }
    cout << "IMPOSSIBLE\n";
}

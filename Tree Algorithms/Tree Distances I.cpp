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
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

int n;
vi g[MN];
int mx1[MN], mx2[MN], child[MN];

void dfs1(int u, int p) {
    mx1[u] = mx2[u] = 0;
    for (int v: g[u]) {
        if (v == p) continue;
        dfs1(v, u);
        if (mx1[v]+1 > mx1[u]) {
            mx2[u] = mx1[u];
            mx1[u] = mx1[v]+1;
            child[u] = v;
        } else if (mx1[v]+1 > mx2[u]) {
            mx2[u] = mx1[v]+1;
        }
    }
}

void dfs2(int u, int p) {
    for (int v: g[u]) {
        if (v == p) continue;
        if (v != child[u]) {
            mx2[v] = mx1[v];
            mx1[v] = mx1[u]+1;
            child[v] = u;
        } else {
            if (mx2[u]+1 > mx1[v]) {
                mx2[v] = mx1[v];
                mx1[v] = mx2[u]+1;
                child[v] = u;
            } else if (mx2[u]+1 > mx2[v]) {
                mx2[v] = mx2[u]+1;
            }
        }
        dfs2(v, u);
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
    dfs1(1, -1);
    dfs2(1, -1);
    rep1(i,1,n) cout << mx1[i] << ' ';
    cout << '\n';
}

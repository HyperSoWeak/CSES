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
int pre[MN];


signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    pre[1] = -1;
    while(sz(q)) {
        int u = q.front(); q.pop();
        for(int v: g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }
    if(!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vi path;
    for(int u=n; u!=-1; u=pre[u]) path.push_back(u);
    reverse(all(path));
    cout << sz(path) << '\n';
    for(int u: path) cout << u << ' ';
    cout << '\n';
}

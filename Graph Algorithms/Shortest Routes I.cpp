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
vector<pii> g[MN];

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }
    // dijkstra
    vi dis(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis[1] = 0;
    pq.emplace(0,1);
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dis[u]) continue;
        for(auto [v, w]: g[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.emplace(dis[v],v);
            }
        }
    }
    rep1(i,1,n) cout << dis[i] << ' ';
    cout << '\n';
}

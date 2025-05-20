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
const int MN = 1005;

int n, a[MN][MN];

pii dir[8] = {
    {1,2},{-1,2},{1,-2},{-1,-2},
    {2,1},{-2,1},{2,-1},{-2,-1},
};

bool valid(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n && a[x][y]==-1;
}

signed main() {
    hyper;
    cin >> n;
    rr(a, -1);
    queue<tiii> q;
    q.emplace(0, 0, 0);
    a[0][0] = 0;
    while (sz(q)) {
        auto [x, y, d] = q.front(); q.pop();
        for (auto [dx, dy]: dir) {
            int nx = x + dx;
            int ny = y + dy;
            if (valid(nx, ny)) {
                a[nx][ny] = d+1;
                q.emplace(nx, ny, d+1);
            }
        }
    }
    rep(i,0,n) rep(j,0,n) cout << a[i][j] << " \n"[j==n-1];
}

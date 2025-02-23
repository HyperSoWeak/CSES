#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int int64_t
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
const int MN = 1005;

int n, m, d[MN][MN], rec[MN][MN], step[MN][MN];
string a[MN];

vector<pii> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
char dc[4] = {'D','U','R','L'};

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];

    rr(d, 0x3f);
    queue<pii> q;
    rep(i,0,n) rep(j,0,m) if(a[i][j] == 'M') {
        q.emplace(i,j);
        d[i][j] = 0;
    }
    while(sz(q)) {
        auto [x,y] = q.front(); q.pop();
        for(auto [dx,dy]: dirs) {
            int nx = x+dx, ny = y+dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '#' || d[nx][ny] != INF) continue;
            d[nx][ny] = d[x][y]+1;
            q.emplace(nx,ny);
        }
    }

    int sx, sy;
    rep(i,0,n) rep(j,0,m) if(a[i][j] == 'A') {
        sx = i, sy = j;
        break;
    }

    q.emplace(sx,sy);
    rec[sx][sy] = -1;
    a[sx][sy] = '#';
    step[sx][sy] = 0;
    while(sz(q)) {
        auto [x,y] = q.front(); q.pop();
        if(x == 0 || x == n-1 || y == 0 || y == m-1) {
            cout << "YES\n";
            string ans;
            while(rec[x][y] != -1) {
                int i = rec[x][y];
                ans += dc[i];
                auto [dx,dy] = dirs[i];
                x -= dx, y -= dy;
            }
            reverse(all(ans));
            cout << sz(ans) << '\n' << ans << '\n';
            return 0;
        }
        rep(i,0,4) {
            auto [dx,dy] = dirs[i];
            int nx = x+dx, ny = y+dy;
            if(a[nx][ny] == '#' || d[nx][ny] <= step[x][y]+1) continue;
            rec[nx][ny] = i;
            a[nx][ny] = '#';
            step[nx][ny] = step[x][y]+1;
            q.emplace(nx, ny);
        }
    }
    cout << "NO\n";
}

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
const int MN = 1005;

int n, m;
int d[MN][MN];
string s[MN];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char dc[] = {'R','L','D','U'};

struct Data { 
    int x, y, dir;
    Data(int x, int y, int dir):
        x(x), y(y), dir(dir) {}
};

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) cin >> s[i];
    queue<Data> q;
    rep(i,0,n) rep(j,0,m) if(s[i][j]=='A') {
        q.emplace(i,j,-1);
        s[i][j] = '#';
    }
    while(sz(q)) {
        auto [x, y, dir] = q.front(); q.pop();
        d[x][y] = dir;
        if(s[x][y]=='B') {
            cout << "YES\n";
            string ans;
            int dir = d[x][y];  
            while(dir != -1) {
                ans += dc[dir];
                int nx = x-dx[dir], ny = y-dy[dir];
                x = nx, y = ny;
                dir = d[x][y];
            }
            reverse(all(ans));
            cout << sz(ans) << '\n' << ans << '\n';
            return 0;
        }
        s[x][y] = '#';
        rep(i,0,4) {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(s[nx][ny]=='#') continue;
            if(s[nx][ny]!='B') s[nx][ny] = '#';
            q.emplace(nx,ny,i);
        }
    }
    cout << "NO\n";
}

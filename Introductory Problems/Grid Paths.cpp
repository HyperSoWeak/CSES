#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 25;
 
string s;
int cnt = 0, b[7][7];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

bool in(int x, int y) { return x >= 0 && x < 7 && y >= 0 && y < 7; }
 
void solve(int n, int x, int y) {
    if(n == 48) {
        if(x == 6 && y == 0) cnt++;
        return;
    }

    if(x == 6 && y == 0) return;
    if(b[x][y]) return;

    vector<bool> vis(4,1);
    rep(i,0,4) if(in(x+dx[i], y+dy[i])) vis[i] = b[x+dx[i]][y+dy[i]];
    if(!vis[0] && vis[1] && !vis[2] && vis[3]) return;
    if(vis[0] && !vis[1] && vis[2] && !vis[3]) return;
    if(in(x+1,y+1) && b[x+1][y+1] && !vis[0] && !vis[1]) return;
    if(in(x-1,y+1) && b[x-1][y+1] && !vis[1] && !vis[2]) return;
    if(in(x-1,y-1) && b[x-1][y-1] && !vis[2] && !vis[3]) return;
    if(in(x+1,y-1) && b[x+1][y-1] && !vis[3] && !vis[0]) return;

    b[x][y] = 1;
    if(s[n] == '?') {
        rep(i,0,4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(in(nx,ny)) solve(n+1, nx, ny);
        }
    } else {
        int i = 0;
        while(s[n] != dir[i]) i++;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(in(nx,ny)) solve(n+1, nx, ny);
    }
    b[x][y] = 0;
}
 
signed main() {
    hyper;
    cin >> s;
    solve(0, 0, 0);
    cout << cnt << '\n';
}

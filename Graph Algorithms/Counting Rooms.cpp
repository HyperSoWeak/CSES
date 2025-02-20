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
string s[MN];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y) {
    s[x][y] = '#';
    rep(i,0,4) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(s[nx][ny] == '.') dfs(nx,ny);
    }
}

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) cin >> s[i];
    int ans = 0;
    rep(i,0,n) rep(j,0,m) {
        if(s[i][j] == '.') {
            dfs(i,j);
            ++ans;
        }
    }
    cout << ans << '\n';
}

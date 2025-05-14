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
constexpr int IINF = 0x3f3f3f3f;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9+7;
constexpr int MN = 2e5+5;

int n, m;
string s[505];

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) cin >> s[i];
    rep(i,0,n) rep(j,0,m) {
        rep(c,0,4) {
            if(c == s[i][j] - 'A') continue;
            if(i > 0 && c == s[i-1][j] - 'A') continue;
            if(j > 0 && c == s[i][j-1] - 'A') continue;
            s[i][j] = c + 'A';
            break;
        }
    }
    rep(i,0,n) cout << s[i] << '\n';
}

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define all(v) v.begin(), v.end()
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 1e5+5;

signed main() {
    hyper;
    int n, m;
    cin >> n >> m;
    vi x(n+5);
    mat dp(n+5, vi(m+5, 0));
    rep1(i,1,n) cin >> x[i];
    if(x[1]) dp[1][x[1]] = 1;
    else rep1(i,1,m) dp[1][i] = 1;
    rep1(i,2,n) {
        if(x[i]) dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1]) % MOD;
        else rep1(j,1,m) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
    }
    int ans = 0;
    rep1(i,1,m) ans = (ans + dp[n][i]) % MOD;
    cout << ans << '\n';
}

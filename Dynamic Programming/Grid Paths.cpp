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
const int MN = 1e6+5;

signed main() {
    hyper;
    int n;
    cin >> n;
    mat dp(n,vi(n,0));
    vector<string> v(n);
    rep(i,0,n) cin >> v[i];
    rep(i,0,n) rep(j,0,n) {
        if(i == 0 && j == 0) dp[i][j] = v[i][j] == '.';
        else if(v[i][j] == '.') {
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n-1][n-1] << '\n';
}

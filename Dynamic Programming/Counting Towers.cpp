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
const int MN = 1e6+5;

int t, n, dp[MN][2];

signed main() {
    hyper;
    dp[1][0] = dp[1][1] = 1;
    rep(i,2,MN) {
        dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 4) % MOD;
    }
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
}

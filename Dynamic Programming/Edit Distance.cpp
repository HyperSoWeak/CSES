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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    mat dp(n+1, vi(m+1, 0));
    rep1(i,1,n) dp[i][0] = i;
    rep1(j,1,m) dp[0][j] = j;
    rep1(i,1,n) rep1(j,1,m) {
        if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
    }
    cout << dp[n][m] << '\n';
}

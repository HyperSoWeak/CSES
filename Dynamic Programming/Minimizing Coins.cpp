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
    int n, x, c[105];
    cin >> n >> x;
    rep(i,0,n) cin >> c[i];
    vi dp(x+1,INF);
    dp[0] = 0;
    rep1(i,1,x) rep(j,0,n) {
        if(i-c[j] >= 0 && dp[i-c[j]] != -1) {
            dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}

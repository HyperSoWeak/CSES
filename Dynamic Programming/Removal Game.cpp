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
const int MOD = 998244353;
const int MN = 2e5+5;
 
signed main() {
    hyper;
    int n;
    cin >> n;
    vi a(n+1);
    int sum = 0;
    rep1(i,1,n) {
        cin >> a[i];
        sum += a[i];
    }
    mat dp(n+5, vi(n+5, 0));
    rep1(i,1,n) dp[i][i] = a[i];
    for(int l=n; l>=1; --l) rep1(r,l+1,n)
        dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
    cout << (sum + dp[1][n]) / 2 << '\n';
}

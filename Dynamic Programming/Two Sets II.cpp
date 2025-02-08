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
const int MN = 2e5+5;
 
signed main() {
    hyper;
    int n;
    cin >> n;
    int w = n * (n + 1) / 2;
    if(w&1) return cout << "0\n", 0;
    w /= 2;
    vi dp(w+1,0);
    dp[0] = 1;
    rep1(i,1,n-1)
        for(int j=w; j>=i; --j)
            dp[j] = (dp[j] + dp[j-i]) % MOD;
    cout << dp[w] << '\n';
}

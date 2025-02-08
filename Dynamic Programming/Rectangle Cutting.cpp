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
    int a, b;
    cin >> a >> b;
    mat dp(a+1, vi(b+1, INF));
    rep1(i,1,a) rep1(j,1,b) {
        if(i == j) dp[i][j] = 0;
        else {
            rep1(k,1,i-1) dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            rep1(k,1,j-1) dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
        }
    }
    cout << dp[a][b] << '\n';
}

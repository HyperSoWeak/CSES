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
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 1005;

int n, m;
int a[MN], b[MN];
int dp[MN][MN], pre[MN][MN];

void print(int i, int j) {
    if(i == 0 || j == 0) return;
    if(pre[i][j] == 0) {
        print(i-1, j-1);
        cout << a[i] << ' ';
    } else if (pre[i][j] == 1) {
        print(i-1, j);
    } else {
        print(i, j-1);
    }
}

signed main() {
    hyper;
    cin >> n >> m;
    rep1(i,1,n) cin >> a[i];
    rep1(i,1,m) cin >> b[i];
    rep1(i,1,n) rep1(j,1,m) {
        if(a[i] == b[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            pre[i][j] = 0;
        } else {
            if (dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                pre[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j-1];
                pre[i][j] = 2;
            }
        }
    }
    cout << dp[n][m] << '\n';
    print(n, m);
    cout << '\n';
}

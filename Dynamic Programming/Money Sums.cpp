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
    int sum = 0;
    vi a(n);
    rep(i,0,n) {
        cin >> a[i];
        sum += a[i];
    }
    bitset<100005> dp;
    dp[0] = 1;
    rep(i,0,n) dp |= dp << a[i];
    cout << dp.count()-1 << '\n';
    rep1(i,1,sum) if(dp[i]) cout << i << ' ';
    cout << '\n';
}

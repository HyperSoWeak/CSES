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

int sum(int x, int y) {
    int a = (x + y);
    int b = (y - x + 1);
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    return ((a % MOD) * (b % MOD)) % MOD;
}

signed main() {
    hyper;
    int n;
    cin >> n;
    int ans = 0, i = 1;
    while(i <= n) {
        int k = n / i;
        int j = n / k;
        int cnt = j - i + 1;
        int sumd = sum(i, j);
        ans = (ans + sumd * k) % MOD;
        i += cnt;
    }
    cout << ans << '\n';
}

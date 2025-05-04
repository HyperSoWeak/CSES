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
const int MN = 2e5+5;

int fastpow(int n, int p, int MOD) {
    int r = 1;
    while (p) {
        if (p & 1) r = (r * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return r;
}

signed main() {
    hyper;
    int n, a, b, c;
    cin >> n;
    rep(i,0,n) {
        cin >> a >> b >> c;
        cout << fastpow(a, fastpow(b, c, MOD-1), MOD) << '\n';
    }
}

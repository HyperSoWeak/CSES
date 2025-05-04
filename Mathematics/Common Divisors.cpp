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

int n, x, cnt[MN];

signed main() {
    hyper;
    cin >> n;
    int mx = -INF;
    rep(i,0,n) {
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    for(int i=mx; i>=1; --i) {
        int c = 0;
        for(int j=i; j<=mx; j+=i) {
            c += cnt[j];
        }
        if(c >= 2) {
            cout << i << '\n';
            return 0;
        }
    }
}

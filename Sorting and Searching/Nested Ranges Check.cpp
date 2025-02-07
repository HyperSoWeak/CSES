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
const int MN = 2e5+5;

struct Range {
    int l, r, pos;
};

bool cmp(Range& a, Range& b) {
    if(a.l == b.l) return a.r > b.r;
    return a.l < b.l;
}

signed main() {
    hyper;
    int n;
    cin >> n;
    vector<Range> a(n);
    rep(i,0,n) {
        cin >> a[i].l >> a[i].r;
        a[i].pos = i;
    }
    sort(all(a), cmp);
    int mn = INF;
    vi ans(n);
    for(int i=n-1; i>=0; --i) {
        Range& x = a[i];
        ans[x.pos] = (x.r >= mn);
        mn = min(mn, x.r);
    }
    rep(i,0,n) cout << ans[i] << " \n"[i==n-1];
    int mx = 0;
    rep(i,0,n) {
        Range& x = a[i];
        ans[x.pos] = (x.r <= mx);
        mx = max(mx, x.r);
    }
    rep(i,0,n) cout << ans[i] << " \n"[i==n-1];
}

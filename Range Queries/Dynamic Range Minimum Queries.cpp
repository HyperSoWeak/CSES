#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define per1(i,a,b) for(int i=a; i>=b; --i)
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
using tiii = tuple<int,int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;
#define lc (x<<1)
#define rc (x<<1|1)

int n;

struct SegTree {
    int a[MN<<2];
    void update(int i, int v, int L=1, int R=n, int x=1) {
        if(L == R) return a[x] = v, void();
        int M = (L+R) >> 1;
        if(i <= M) update(i, v, L, M, lc);
        else update(i, v, M+1, R, rc);
        a[x] = min(a[lc], a[rc]);
    }
    int query(int l, int r, int L=1, int R=n, int x=1) {
        if(l <= L && R <= r) return a[x];
        int M = (L+R) >> 1;
        int res = INF;
        if(l <= M) res = min(res, query(l, r, L, M, lc));
        if(r > M) res = min(res, query(l, r, M+1, R, rc));
        return res;
    }
} seg;

signed main() {
    hyper;
    int q;
    cin >> n >> q;
    rep1(i,1,n) {
        int x;
        cin >> x;
        seg.update(i, x);
    }
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) seg.update(x, y);
        else cout << seg.query(x, y) << '\n';
    }
}

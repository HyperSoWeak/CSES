#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
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
const int LOGN = 20;

struct Fenwick {
    vector<int> v;
    int sz;
    Fenwick(int n) {
        v.resize(n+1, 0);
        sz = n;
    }
    int lb(int x) { return x&-x; }
    void add(int p, int x) {
        for(int i=p; i<=sz; i+=lb(i)) v[i] += x;
    }
    int query(int p) {
        int sum = 0;
        for(int i=p; i>0; i-=lb(i)) sum += v[i];
        return sum;
    }
    int rsum(int l, int r) {
        return query(r) - query(l-1);
    }
};

int n, q, a[MN];

signed main() {
    hyper;
    cin >> n >> q;
    Fenwick f(n);
    rep1(i,1,n) {
        cin >> a[i];
        f.add(i, a[i]);
    }
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            f.add(x, y-a[x]);
            a[x] = y;
        } else {
            cout << f.rsum(x, y) << '\n';
        }
    }
}

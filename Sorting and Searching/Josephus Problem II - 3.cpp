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

struct Fenwick {
    int n;
    vi v;
    Fenwick(int n) : n(n), v(n+1) {}
    int lb(int x) { return x & -x; }
    void add(int x, int val) {
        for(; x <= n; x += lb(x)) v[x] += val;
    }
    int sum(int x) {
        int res = 0;
        for(; x; x -= lb(x)) res += v[x];
        return res;
    }
    int sum(int l, int r) { return sum(r) - sum(l-1); }
    int getPos(int p) {
        int l = 1, r = n;
        while(l < r) {
            int m = (l+r)/2;
            if(sum(m) >= p) r = m;
            else l = m+1;
        }
        return l;
    }
};

signed main() {
    hyper;
    int n, k;
    cin >> n >> k;
    Fenwick bit(n);
    rep1(i,1,n) bit.add(i,1);
    int pos = k % n;
    while(n) {
        int x = bit.getPos(pos+1);
        bit.add(x,-1);
        cout << x << ' ';
        --n;
        if(n) pos = (pos+k) % n;
    }
    cout << '\n';
}

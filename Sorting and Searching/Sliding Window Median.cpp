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
constexpr int IINF = 0x3f3f3f3f;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9+7;
constexpr int MN = 2e5+5;

int n, k, a[MN];
multiset<int> l, r;

void insert(int x) {
    int m = sz(l) ? *l.rbegin() : 0;
    if(x >= m) {
        r.insert(x);
        if(sz(r) > sz(l)) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    } else {
        l.insert(x);
        if(sz(l) > sz(r)+1) {
            r.insert(*l.rbegin());
            l.erase(--l.end());
        }
    }
}

void remove(int x) {
    if(l.count(x)) {
        l.erase(l.find(x));
        if(sz(r) > sz(l)) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    } else {
        r.erase(r.find(x));
        if(sz(l) > sz(r)+1) {
            r.insert(*l.rbegin());
            l.erase(--l.end());
        }
    }
}

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    rep(i,0,k) insert(a[i]);
    cout << *l.rbegin() << ' ';
    rep(i,k,n) {
        remove(a[i-k]);
        insert(a[i]);
        cout << *l.rbegin() << ' ';
    }
    cout << '\n';
}

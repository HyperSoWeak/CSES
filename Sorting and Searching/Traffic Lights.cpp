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

signed main() {
    hyper;
    int n, x;
    cin >> x >> n;
    vi p(n);
    set<int> s{0, x};
    rep(i,0,n) {
        cin >> p[i];
        s.insert(p[i]);
    }
    vi ans(n);
    int mx = 0;
    for(auto it = next(s.begin()); it != s.end(); ++it) {
        int l = *prev(it), r = *it;
        mx = max(mx, r-l);
    }
    for(int i=n-1; i>=0; --i) {
        ans[i] = mx;
        auto it = s.find(p[i]);
        int l = *prev(it), r = *next(it);
        s.erase(it);
        mx = max(mx, r-l);
    }
    rep(i,0,n) cout << ans[i] << ' ';
    cout << '\n';
}

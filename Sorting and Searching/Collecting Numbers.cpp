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
const int MOD = 1e9+7;
const int MN = 2e5+5;

signed main() {
    hyper;
    int n;
    cin >> n;
    vector<pii> a(n);
    rep(i,0,n) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(),a.end());
    int ans = 0, x = INF;
    rep(i,0,n) {
        if(x > a[i].se) ++ans;
        x = a[i].se;
    }
    cout << ans << '\n';
}

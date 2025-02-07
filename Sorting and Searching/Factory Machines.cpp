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

int n, t, k[MN];

bool check(int m) {
    int cnt = 0;
    rep(j,0,n) {
        cnt += m/k[j];
        if(cnt >= t) return 1;
    }
    return 0;
}

signed main() {
    hyper;
    cin >> n >> t;
    rep(i,0,n) cin >> k[i];
    int l = 0, r = 1e18;
    while(l < r) {
        int m = (l+r)/2;
        if(check(m)) r = m;
        else l = m+1;
    }
    cout << l << '\n';
}

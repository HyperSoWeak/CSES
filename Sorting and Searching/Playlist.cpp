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
    int n, x;
    set<int> s;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    int mx = 0, i = 0;
    rep(j,0,n) {
        while(s.count(a[j])) s.erase(a[i++]);
        s.insert(a[j]);
        mx = max(mx, j-i+1);
    }
    cout << mx << '\n';
}

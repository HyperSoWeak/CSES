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
    int n, m, a[MN], p[MN];
    cin >> n >> m;
    rep1(i,1,n) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int ans = 1;
    rep1(i,2,n) ans += (p[i] < p[i-1]);
    while(m--) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(a[x] < n && x < p[a[x]+1] && y > p[a[x]+1]) ++ans;
        if(a[x] > 1 && x < p[a[x]-1] && y > p[a[x]-1]) --ans;
        if(a[y] < n && y > p[a[y]+1] && x < p[a[y]+1]) --ans;
        if(a[y] > 1 && y > p[a[y]-1] && x < p[a[y]-1]) ++ans;
        if(a[x] - a[y] == 1) --ans;
        if(a[y] - a[x] == 1) ++ans;
        swap(p[a[x]], p[a[y]]);
        swap(a[x], a[y]);
        cout << ans << '\n';
    }
}

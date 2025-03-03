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

int n, q, a[MN];
int f[MN][LOGN], lg[MN];

void pre() {
    lg[1] = 0;
    rep(i,2,MN) lg[i] = lg[i/2]+1;
    rr(f,0x3f);
}

void build() {
    rep1(i,1,n) f[i][0] = a[i];
    rep1(j,1,lg[n]+1) for(int i=1; i+(1<<j)-1<=n; ++i) {
        f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
    }
}

int query(int l, int r) {
    int j = lg[r-l+1];
    return min(f[l][j], f[r-(1<<j)+1][j]);
}

signed main() {
    hyper;
    pre();
    cin >> n >> q;
    rep1(i,1,n) cin >> a[i];
    build();
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l,r) << '\n';
    }
}

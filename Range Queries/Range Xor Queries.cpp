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

int n, q, a, b;
int ps[MN];

signed main() {
    hyper;
    cin >> n >> q;
    rep1(i,1,n) {
        cin >> a;
        ps[i] = ps[i-1] ^ a;
    }
    rep(i,0,q) {
        cin >> a >> b;
        cout << (ps[b] ^ ps[a-1]) << '\n';
    }
}
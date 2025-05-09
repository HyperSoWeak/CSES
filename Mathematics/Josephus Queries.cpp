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

int sol(int n, int k) {
    if(n == 1) return 1;
    if(2*k <= n+1) return (2*k-1)%n+1;
    int r = (n+1)/2;
    int t = sol(n-r, k-r);
    if(n&1) return 2*t+1;
    return 2*t-1;
}

signed main() {
    hyper;
    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        cout << sol(n, k) << '\n';
    }
}

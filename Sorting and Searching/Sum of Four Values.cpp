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
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 1005;

int n, t, a[MN];
unordered_map<int, vector<pii>> mp;

signed main() {
    hyper;
    cin >> n >> t;
    rep1(i,1,n) cin >> a[i];
    rep1(i,1,n-1) {
        rep1(j,i+1,n) {
            int sum = a[i] + a[j];
            if(mp.count(t-sum)) {
                for(auto [x, y]: mp[t-sum]) {
                    if(x!=i && x!=j && y!=i && y!=j) {
                        cout << x << ' ' << y << ' ' << i << ' ' << j << '\n';
                        return 0;
                    }
                }
            }
            mp[sum].emplace_back(i, j);
        }
    }
    cout << "IMPOSSIBLE\n";
}

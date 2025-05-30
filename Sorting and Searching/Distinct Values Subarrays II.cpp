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
using tiii = tuple<int,int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

int n, k, a[MN];
unordered_map<int, int> m;

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    int ans = 0, j = 0;
    rep(i,0,n) {
        m[a[i]]++;
        while(sz(m) > k) {
            m[a[j]]--;
            if(m[a[j]] == 0) m.erase(a[j]);
            j++;
        }
        ans += i - j + 1;
    }
    cout << ans << '\n';
}
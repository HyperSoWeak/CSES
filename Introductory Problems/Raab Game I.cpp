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
const int MN = 2e5+5;

signed main() {
    hyper;
    int t, n, a, b;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        if(a+b > n || (a == 0 && b != 0) || (a != 0 && b == 0)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep1(i,1,n) cout << i << ' ';
        cout << '\n';
        rep1(i,a+1,a+b) cout << i << ' ';
        rep1(i,1,a) cout << i << ' ';
        rep1(i,a+b+1,n) cout << i << ' ';
        cout << '\n';
    }
}

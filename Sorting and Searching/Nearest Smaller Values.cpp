#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int int64_t
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

signed main() {
    hyper;
    int n, x;
    cin >> n;
    stack<pii> s;
    s.emplace(-INF, 0);
    rep1(i,1,n) {
        cin >> x;
        while(s.top().fi>=x) s.pop();
        cout << s.top().se << ' ';
        s.emplace(x, i);
    }
    cout << '\n';
}

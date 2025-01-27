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
const int MOD = 998244353;
const int MN = 1e6+5;

bool b[MN];

signed main() {
    hyper;
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if(sum & 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    sum /= 2;
    int s = 0;
    vi v;
    for(int i=n; i>=1; --i) {
        if(s + i > sum) {
            v.push_back(sum - s);
            b[sum - s] = 1;
            break;
        }
        s += i;
        v.push_back(i);
        b[i] = 1;
        if(s == sum) break;
    }
    cout << v.size() << '\n';
    for(int x: v) cout << x << ' ';
    cout << '\n';
    cout << n - v.size() << '\n';
    rep1(i,1,n) if(!b[i]) cout << i << ' ';
    cout << '\n';
}

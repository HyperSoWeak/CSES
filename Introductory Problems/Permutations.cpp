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
const int MN = 5005;

signed main() {
    hyper;
    int n;
    cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for(int i=2; i<=n; i+=2) cout << i << ' ';
    for(int i=1; i<=n; i+=2) cout << i << ' ';
    cout << '\n';
}

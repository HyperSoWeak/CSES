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
const int MN = 25;

int pow10(int n) {
    int res = 1;
    rep(i,0,n) res *= 10;
    return res;
}

signed main() {
    hyper;
    int q, k;
    cin >> q;
    while(q--) {
        cin >> k;
        int d = 1;
        while(k > d * 9 * pow10(d-1)) {
            k -= d * 9 * pow10(d-1);
            d++;
        }
        int t = (k-1) / d;
        int r = (k-1) % d;
        int num = pow10(d-1) + t;
        cout << to_string(num)[r] << '\n';
    }
}

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
const int MN = 1e6+5;

signed main() {
    hyper;
    int n, x;
    cin >> n;
    vi a;
    cin >> x;
    a.push_back(x);
    rep(i,1,n) {
        cin >> x;
        if(a.back() < x) a.push_back(x);
        else *lower_bound(all(a),x) = x;
    }
    cout << sz(a) << '\n';
}

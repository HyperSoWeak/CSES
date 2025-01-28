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
const int MN = 2e5+5;

int n, a[MN], b[MN], d[MN*2];
vi v;

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) {
        cin >> a[i] >> b[i];
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    rep(i,0,n) {
        int x = lower_bound(v.begin(),v.end(),a[i])-v.begin();
        int y = lower_bound(v.begin(),v.end(),b[i])-v.begin();
        ++d[x], --d[y];
    }
    int mx = d[0];
    rep(i,1,n*2) {
        d[i] += d[i-1];
        mx = max(mx,d[i]);
    }
    cout << mx << '\n';
}

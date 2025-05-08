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

int n, k, a[MN];

bool check(int t) {
    int sum = 0, cnt = 1;
    rep(i,0,n) {
        if(sum + a[i] > t) {
            sum = a[i];
            if(sum > t) return 0;
            cnt++;
            if(cnt > k) return 0;
        } else {
            sum += a[i];
        }
    }
    return 1;
}

signed main() {
    hyper;
    cin >> n >> k;
    int sum = 0;
    rep(i,0,n) {
        cin >> a[i];
        sum += a[i];
    }
    int l = 1, r = sum;
    while(l < r) {
        int m = (l+r) / 2;
        if(check(m)) r = m;
        else l = m+1;
    }
    cout << l << '\n';
}

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
constexpr int IINF = 0x3f3f3f3f;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9+7;
constexpr int MN = 2e5+5;

int n, a[105][105];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) rep(j,0,n) {
        bool has[205] = {0};
        rep(k,0,i) has[a[k][j]] = 1;
        rep(k,0,j) has[a[i][k]] = 1;
        int x = 0;
        while(has[x]) x++;
        a[i][j] = x;
        cout << x << " \n"[j==n-1];
    }
}

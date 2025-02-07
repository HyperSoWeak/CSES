#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define all(v) v.begin(), v.end()
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

signed main() {
    hyper;
    int n, k;
    cin >> n >> k;
    int sn = sqrt(n-1)+1;
    mat a(sn);
    rep(i,0,n) a[i/sn].push_back(i+1);

    int pos = k % n;
    while(n) {
        int sum = 0, i = 0;
        while(sum + a[i].size() < pos + 1) {
            sum += a[i].size();
            ++i;
        }
        cout << a[i][pos-sum] << ' ';
        a[i].erase(a[i].begin() + pos - sum);
        --n;
        if(n) pos = (pos + k) % n;
    }
    cout << '\n';
}

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

int table[] = {0, 0, 6, 28, 96};

signed main() {
    hyper;
    int n;
    cin >> n;
    rep1(i,1,n) {
        if(i <= 4) cout << table[i] << '\n';
        else {
            int a = (i-4) * 4 + 4;
            int b = (i-4) * 4;
            int c = (i-4) * (i-4);
            int s = i * i - 1;
            int sum = 4*(s-2) + 8*(s-3) + a*(s-4) + b*(s-6) + c*(s-8);
            cout << sum / 2 << '\n';
        }
    }
}

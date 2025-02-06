#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
// #define int long long
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
// const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    hyper;
    int n, k;
    cin >> n >> k;
    ordered_set<int> s;
    rep1(i,1,n) s.insert(i);
    int pos = k % n;
    while(!s.empty()) {
        int x = *s.find_by_order(pos);
        cout << x << ' ';
        s.erase(x);
        if(s.size()) pos = (pos + k) % s.size();
    }
    cout << '\n';
}

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve(){
    int n;cin >> n;
    int minL = INT_MAX,cl = INT_MAX;
    int maxR = 0,cr = INT_MAX;
    int maxLength = 0,maxCost = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int l,r,c;cin >> l >> r >> c;
        if(l < minL){
            minL = l;cl = INT_MAX;
        } if (l == minL){
            cl = min(cl,c);
        }

        if (r > maxR){
            maxR = r;cr = INT_MAX;
        } if (r == maxR){
            cr = min(cr,c);
        }

        if (maxLength < r-l+1){
            maxLength = r-l+1,maxCost = INT_MAX;
        } if (maxLength == r-l+1){
            maxCost = min(maxCost,c);
        }

        int ans = cl+cr;
        if (maxLength == maxR - minL + 1){
            ans = min(ans,maxCost);
        }
        cout << ans << endl;
    }

}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

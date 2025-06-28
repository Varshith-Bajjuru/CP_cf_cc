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
    vi a(n);rep(i,0,n) cin >> a[i];
    string s;cin >> s;
    int q;cin >> q;
    int xorr1 = 0,xorr2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') xorr1 ^= a[i];
        else xorr2 ^= a[i];
    }
    vi prefixXorr(n);
    prefixXorr[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefixXorr[i] = prefixXorr[i-1]^a[i];
    }

    while (q--){
        int type;cin >> type;
        if (type == 1){
            int l,r;cin >> l >> r;
            l--,r--;
            int xorr;
            if (l == 0){
                xorr = prefixXorr[r];
            }else{
                xorr = prefixXorr[r]^prefixXorr[l-1];
            }
            xorr1 ^= xorr;
            xorr2 ^= xorr;
        }else{
            int g;cin >> g;
            if (g == 0){
                cout << xorr1 << " ";
            }else{
                cout << xorr2 << " ";
            }
        }
    }
    cout << endl;
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

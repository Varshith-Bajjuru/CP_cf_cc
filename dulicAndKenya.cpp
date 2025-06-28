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

pii reduce(int a, int b) {
    int g = gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

void solve(){
    int n;cin >> n;
    string s;cin >> s;

    vi ans(n,1);
    int a = 0,b = 0;
    map<pii,int> mp;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D'){
            a++;
        }else{
            b++;
        }
        pii x = reduce(a,b);
        mp[x]++;
        ans[i] = mp[x];
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
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

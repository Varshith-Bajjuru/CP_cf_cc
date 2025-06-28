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
#define mp make_pair

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve(){
    int n,m;cin >> n >> m;
    if(m < n || m > n*(n+1)/2){
        cout << -1 << endl;
        return;
    }
    vi ans(n+1);
    for (int i = 1; i <= n; ++i) {
        ans[i] = i;
    }

    int rem = n*(n+1)/2 - m;
    int pnode = n;
    while (rem > 0){
        if (rem >= pnode){
            rem -= (pnode-1);
            ans[pnode] = 1;
        }else{
            ans[pnode] = pnode - rem;
            rem = 0;
        }
        pnode--;
    }

    int ptr = 1;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == i){
            ptr = i;
        }
    }

    cout << ptr << endl;
    for (int i = 1; i < ptr; ++i) {
        cout << ptr << " " << i << endl;
    }
    for (int i = ptr+1; i <= n; ++i) {
        cout << ans[i] << " " << i << endl;
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

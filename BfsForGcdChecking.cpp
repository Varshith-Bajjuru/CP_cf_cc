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
    int n,g;cin >> n >> g;
    vi a(n);rep(i,0,n)cin >> a[i];
    queue<pair<int,int>> q;
    unordered_map<int,int> mp;

    for(int num : a){
        int div = num;
        if (div == g){
            cout << 1 << endl;
            return;
        }
        if (mp.count(div) == 0) mp[div] = 1;
        q.emplace(div,1);
    }

    while (!q.empty()){
        auto [curr,steps] = q.front();
        q.pop();
        for(int num : a){
            int div = gcd(curr,num);
            if (div == g){
                cout << steps+1 << endl;
                return;
            }
            if (mp.count(div) == 0){
                mp[div] = steps+1;
                q.emplace(div,steps+1);
            }
        }
    }
    cout << -1 << endl;
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

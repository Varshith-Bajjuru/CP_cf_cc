#include <bits/stdc++.h>
using namespace std;

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
    int n,m,x;
    cin >> n >> m >> x;
    vector<pair<int,int>> v(n);
    vi a(n);rep(i,0,n){
        cin >> a[i];
        v[i] = {a[i],i};
    }
    sort(all(v));
    vi ans(n);
    vi towers(m);

    int t = 0;
    for (int i = n-m; i < n; ++i) {
        towers[t] = v[i].first;
        ans[v[i].second] = t;
        t++;
    }

    t = 0;
    for (int i = n-m-1; i >= 0; --i) {
        towers[t%m] += v[i].first;
        ans[v[i].second] = t%m;
        t++;
    }

    if (*max_element(all(towers)) - *min_element(all(towers)) <= x){
        cout << "Yes" << endl;
        for(int i : ans){
            cout << i+1 << " ";
        }
        cout << endl;
        return;
    }else{
        cout << "No" << endl;
        return;
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

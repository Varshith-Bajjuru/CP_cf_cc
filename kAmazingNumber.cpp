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
    int n;cin >> n;
    bool allSame = true;
    vi a(n);rep(i,0,n) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[0]){
            allSame = false;
        }
    }
    vi ans(n+1,-1);
    if (allSame){
        for (int i = 0; i < n; ++i) {
            cout << a[0] << " ";
        }
        cout << endl;
        return;
    }else{
        ans[1] = -1;
    }

    map<int,vi> freq;
    for(int i : a) if (freq[i].empty()) freq[i].push_back(-1);
    for (int i = 0; i < n; ++i) {
        freq[a[i]].push_back(i);
    }
    for(auto p : freq){
        freq[p.first].push_back(n);
    }

    vi dp(n+1,INT_MAX);
    for(auto p : freq){
        int maxi = 0;
        for (int i = 1; i < p.second.size(); ++i) {
            maxi = max(maxi,p.second[i] - p.second[i-1]);
        }
        dp[maxi] = min(dp[maxi],p.first);
    }

    int idx = n;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] != INT_MAX){
            idx = i;
            break;
        }
    }
    for (int i = 1; i < idx; ++i) {
        ans[i] = -1;
    }
    ans[idx] = dp[idx];
    for (int i = idx+1; i <= n; ++i) {
        ans[i] = min(dp[i],ans[i-1]);
    }
    for (int i = 1; i <= n; ++i) {
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

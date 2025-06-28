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

int getCoins(vi &a,int idx,int turn,vector<vector<int>> &dp){
    if (idx >= a.size()){
        return 0;
    }
    if (dp[idx][turn] != -1) return dp[idx][turn];
    int pick1 = INT_MAX,pick2 = INT_MAX;
    if (turn == 0){
        pick1 = (a[idx] == 1) + getCoins(a,idx+1,1,dp);
        if (idx+1 < a.size()){
            pick2 = (a[idx] == 1) + (a[idx+1] == 1) + getCoins(a,idx+2,1,dp);
        }
    }else{
        pick1 = getCoins(a,idx+1,0,dp);
        if (idx+1 < a.size()){
            pick2 = getCoins(a,idx+2,0,dp);
        }
    }
    return dp[idx][turn] = min(pick1,pick2);
}

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];
    vector<vector<int>> dp(n+1,vector<int> (3,-1));
    int x = getCoins(a,0,0,dp);
    cout << x << endl;
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

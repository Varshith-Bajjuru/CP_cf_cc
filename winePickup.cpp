#include <bits/stdc++.h>
#include "set"
#include "unordered_map"
#include "algorithm"
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

ll MOD = 1e9+7;

int helper(vector<int> &p,int year,int left,int right,vector<vector<int>> dp){
    if (left == right){
        return year*p[left];
    }
    if (dp[left][right] != 0) return dp[left][right];
    int pickLeft = year*p[left] + helper(p,year+1,left+1,right,dp);
    int pickRight = year*p[right] + helper(p,year+1,left,right-1,dp);

    return dp[left][right] = max(pickLeft,pickRight);
}

void solve(){
    vector<int> prices = {2,3,5,1,4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (n,0));
    cout << helper(prices,1,0, 4,dp) << endl;
}


int main() {
    fast_io();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
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

void print(map<int,vi> &mp){

    for(auto &p : mp){
        cout << p.first << ":" ;
        for(int i : p.second){
            cout << i << " ";
        }
    }
    cout << endl;
}

int f(vector<pair<int,int>> &v,int idx,vector<int> &dp){
    if (idx >= v.size()) return 0;
    if (dp[idx] != -1) return dp[idx];

    int pick = v[idx].first*v[idx].second + f(v,idx+2,dp);
    int notPick = f(v,idx+1,dp);

    return dp[idx] = max(pick,notPick);
}

int getAns(vector<pair<int,int>> &v,int i,int j){
    vector<pair<int,int>> v1;
    for (int k = i; k < j; ++k) {
        v1.push_back(v[k]);
    }

    vi dp(j-i+1,-1);
    return f(v1,0,dp);
}

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n)cin >> a[i];
    map<int,int> freq;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }
    int ans = 0;

    vector<pair<int,int>> v;
    for(auto &p : freq){
        v.emplace_back(p.first,p.second);
    }
    int i = 0,j = 1;
    while (i < v.size()){
        while(v[j].first-1 == v[j-1].first && j < n){
            j++;
        }
        ans += getAns(v,i,j);
        i = j;
        j++;
    }

    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

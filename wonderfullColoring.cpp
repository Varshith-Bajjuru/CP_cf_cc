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
    int n,k;cin >> n >> k;
    vi a(n);rep(i,0,n) cin >> a[i];
    unordered_map<int,vector<int>> freq;
    for (int i = 0; i < n; ++i) {
        freq[a[i]].push_back(i);
    }
    vi ans(n,0);
    map<int,vi> freq2;
    for(const auto& p : freq){
        if (p.second.size() >= k){
            int clr = 1;
            for (int j : p.second) {
                if (clr > k) break;
                ans[j] = clr++;
            }
        }else{
          freq2[p.first] = p.second;
        }
    }

    int clr = 1;
    for(const auto& p : freq2){
        for (int i : p.second) {
            ans[i] = clr++;
            if (clr > k){
                clr = 1;
            }
        }
    }

    vi toRemove;
    int minK = INT_MAX;
    map<int,int> ansFreq;
    for(int i : ans) ansFreq[i]++;
    for(auto p : ansFreq){
        if (p.first != 0){
            minK = min(minK,p.second);
        }
    }
    for(auto p : ansFreq){
        if (p.second > minK){
            toRemove.push_back(p.first);
        }
    }
    map<int,int> idxs;
    for(int i = 0;i < n;i++){
        idxs[ans[i]] = i;
    }
    for(int i : toRemove){
        ans[idxs[i]] = 0;
    }
    for(int j : ans){
        cout << j << " ";
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

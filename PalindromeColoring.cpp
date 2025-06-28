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
    string s;cin >> s;
    if (n == k){
        cout << 1 << endl;
        return;
    }
    unordered_map<char,int> freq;
    for (int i = 0; i < n; ++i) {
        freq[s[i]]++;
    }
    int twos = 0,ons = 0;
    for(auto p : freq){
        if (p.second%2 == 0){
            twos += p.second/2;
        }else{
            twos += p.second/2;
            ons++;
        }
    }
    int ans = 2*(twos/k);
    ons += 2*(twos%k);
    if (ons >= k){
        ans ++;
    }
    cout << ans << endl;
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

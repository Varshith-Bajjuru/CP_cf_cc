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

int getAns(string &s){
    int n = (int)s.size();
    vi notGd;
    notGd.push_back(0);
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == s[i+1]){
            notGd.push_back(i);
        }
    }
    notGd.push_back(n-1);
    int ans = 0;
    for (int i = 1; i < notGd.size(); ++i) {
        int x = notGd[i] - notGd[i-1];
        ans += x*(x+1)/2;
    }
    return ans;
}

void solve(){
    string s;cin >> s;
    int n = (int)s.size();

    bool allQ = true;
    for (char i : s) if (i != '?') allQ = false;
    if (allQ || n == 1){
        cout << n*(n+1)/2 << endl;
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

#include <bits/stdc++.h>
#include "set"
#include "unordered_map"
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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int digits(ll n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

ll power(int a,int b){
    if (b == 0) return 1;
    ll x  = power(a,b/2);
    if (b%2 == 0){
        return x*x;
    } else{
        return x*x*a;
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    unordered_map<ll,vi> mp;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
        if (mp[a[i]].size() > 1) ok = true;
    }
    ll maxAns = 0;
    ll m = 0,b = 0;
    if (ok){
        for(auto x : mp){
            for (int i = 0; i < x.second.size(); ++i) {
                int j = i+1;
                m = min(x.second[i],x.second[j]);
                b = min((n-1-x.second[i]),(n-1-x.second[j]));
                maxAns = max((ll)(m+b+1),maxAns);
            }
        }
        cout << maxAns << endl;
    } else{
        cout << -1 << endl;
    }
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
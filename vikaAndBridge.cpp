#include <bits/stdc++.h>
#include "set"
#include <cmath>
#include "unordered_map"
#include "algorithm"
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

int MOD = 1e9+7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(int n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

int power(int a, int b){
    if (b == 0) return 1;
    int x  = power(a, b/2);
    if (b % 2 == 0){
        return x * x;
    } else{
        return x * x * a;
    }
}

int powermod(int x, int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int bitCount(int num) {
    return num ? (int)log2(num) + 1 : 0;
}

void solve(){
    int n,k;
    cin >> n >> k;
    vi c(n);
    rep(i,0,n) cin >> c[i];

    map<int,vi> mp;
    for (int i = 1; i <= k; ++i) {
        mp[i].push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        mp[c[i]].push_back(i+1);
    }
    for (int i = 1; i <= k; ++i) {
        mp[i].push_back(n+1);
    }

    int ans = INT_MAX;
    for(const auto &p : mp){
        priority_queue<int> pq;
        for (int i = 1; i < p.second.size(); ++i) {
            pq.push(p.second[i] - p.second[i-1]-1);
        }
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        ans = min(ans,max(num1/2,num2));
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

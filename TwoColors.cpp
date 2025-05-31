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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(ll n) {
    return (n > 0) && ((n & (n - 1)) == 0);
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

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    for (ll i = 0; i < m; ++i) {
        a[i] = min(a[i],n-1);
    }

    ll total = 0;
    ll sum = 0;
    ll idx = m-1;
    for (ll i = 0; i < m; ++i) {
        while (idx >= 0 && a[idx] + a[i] >= n ){
            sum += a[idx];
            idx--;
        }
        total += sum + (m - 1 - idx)*(a[i] - n + 1);
    }

    for (ll i = 0; i < m; ++i) {
        if (2*a[i] >= n){
            total -= (2*a[i] - n + 1);
        }
    }

    cout << total << endl;
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
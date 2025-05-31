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

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,0,n) cin >> v[i];
    vector<ll> a = v;
    sort(all(v),[](int a,int b){
        return a > b;
    });

    if(k == 1){
        ll ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans,a[i] + a[0]);
        }
        for (int i = 0; i < n-1; ++i) {
            ans = max(ans , a[n-1] + a[i]);
        }
        cout << ans << endl;
        return;
    }
    ll ans = 0;
    for (int i = 0; i < k+1; ++i) {
        ans += v[i];
    }
    cout << ans << endl;
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

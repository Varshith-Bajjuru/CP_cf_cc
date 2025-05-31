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

ll MOD = 109+7;

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

//void solve() {
//    int l,r,d,u;
//    cin >> l >> r >> d >> u;
//    bool yes = false;
//    int side = l*l + u*u;
//    int diag = l*l + r*r;
//    if (side == r*r + u*u && side == r*r + d*d && side == d*d + l*l && diag == u*u + d*d) yes = true;
//    if (yes) {
//        cout << "YES" << endl;
//        return;
//    }
//    cout << "NO" << endl;
//}
//
//void solve(){
//    ll n;
//    cin >> n;
//    vector<ll> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    if (n == 1){
//        cout << a[0] << endl;
//        return;
//    }
//    ll sum = 0;
//    for (int i = 0; i < n; ++i) {
//        sum += a[i];
//    }
//    cout << sum - (n-1) << endl;
//}
//
//void solve(){
//    ll x;
//    cin >> x;
//    if (isPowerOf2(x) || isPowerOf2(x+1)){
//        cout << -1 << endl;
//        return;
//    }
//    ll p = 1;
//    while(p*2 < x){
//        p *= 2;
//    }
//    cout << p-1 << endl;
//}

void solve(){
    
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
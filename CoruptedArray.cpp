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
    ll n;cin >> n;
    vector<ll> b(n+2);
    for (int i = 0; i < n+2; ++i) {
        cin >> b[i];
    }
    vector<ll> sorted = b;
    sort(all(sorted));

    ll sum1 = sorted[n+1],prev1 = sorted[n];
    ll sum2 = sorted[n],prev2 = sorted[n+1];

    ll prevSum = 0;
    for (int i = 0; i < n; ++i) {
        prevSum += sorted[i];
    }

    if (prevSum == sum1 || prevSum == sum2){
        for (int i = 0; i < n; ++i) {
            cout << sorted[i] << " ";
        }
        cout << endl;
        return;
    }

    {
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (prevSum + prev1 - sorted[i] == sum1){
                idx = i;
                break;
            }
        }
        if (idx > -1){
            cout << prev1 << " ";
            for (int i = 0; i < n; ++i) {
                if (idx != i){
                    cout << sorted[i] << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    {
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (prevSum + prev2 - sorted[i] == sum2){
                idx = i;
                break;
            }
        }
        if (idx > -1){
            cout << prev2 << " ";
            for (int i = 0; i < n; ++i) {
                if (idx != i){
                    cout << sorted[i] << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
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
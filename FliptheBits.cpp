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
    int n;cin >> n;
    string a,b;
    cin >> a >> b;
    vector<pair<int,int>> v;
    int j = 0;
    int ons = 0;int zrs = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1')ons++;
        else zrs++;
        if (ons == zrs){
            v.emplace_back(j,i);
            j = i+1;
        }
    }

    for (auto i : v) {
        int st = i.first;
        int ed = i.second;
        if (a[st] == b[st]) continue;
        else{
            for (int k = st; k <= ed ; ++k) {
                if (a[k] == '0')a[k] = '1';
                else a[k] = '0';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

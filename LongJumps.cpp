#include <bits/stdc++.h>
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll maxAns = 0;
    for (ll i = n - 1; i >= 0; --i) {
        if (i + a[i] < n) {
            dp[i] = a[i] + dp[i + a[i]];
        } else {
            dp[i] =  a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        maxAns = max(maxAns,dp[i]);
    }
    cout << maxAns << endl;
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
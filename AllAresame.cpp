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

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll minEle = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        minEle = min(minEle,a[i]);
    }
    for (int i = 0; i < n; ++i) {
        a[i] -= minEle;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = gcd(ans,a[i]);
    }
    if(ans < 1){
        cout << -1 << endl;
        return;
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
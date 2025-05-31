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

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll gcdOdd = 0;
    ll gcdEven = 0;
    for (int i = 0; i < n; ++i) {
        if (i%2 == 0){
            gcdEven = gcd(gcdEven,a[i]);
        }
        else{
            gcdOdd = gcd(gcdOdd,a[i]);
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (i%2 == 0 && a[i]%gcdOdd == 0){
            ok = false;
            break;
        }
    }
    if (ok){
        cout << gcdOdd << endl;
        return;
    }
    ok = true;
    for (int i = 0; i < n; ++i) {
        if(i%2 != 0 && a[i]%gcdEven == 0){
            ok = false;
        }
    }
    if(ok){
        cout << gcdEven << endl;
        return;
    }
    cout << 0 << endl;
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
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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> pos;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '*') pos.push_back(i);
    }

    if (pos.size() == 1) {
        cout << 1 << endl;
        return;
    }

    ll cnt = 2;  // We always mark the first and last '*'
    ll last = pos[0]; // Leftmost '*'
    ll rightmost = pos.back(); // Rightmost '*'

    while (true) {
        ll next = last;
        // Move as far right as possible within k distance
        for (ll i = 0; i < pos.size(); ++i) {
            if (pos[i] > last && pos[i] - last <= k) {
                next = pos[i];
            } else if (pos[i] - last > k) {
                break;
            }
        }

        if (next == last) break; // No further movement possible
        last = next;
        cnt++;

        if (last == rightmost) break;
    }

    cout << cnt-1 << endl;
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
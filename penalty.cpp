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

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;

    string favA = s, favB = s;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0 && s[i] == '?') favA[i] = '1'; // Maximize team A's advantage
        if (i % 2 == 1 && s[i] == '?') favB[i] = '1'; // Maximize team B's advantage
    }

    ll matchFA = 10, matchFB = 10;

    ll matchWonA = 0, matchWonB = 0, matchRemA = 5, matchRemB = 5;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) { // Team A's turn
            if (favA[i] == '1') matchWonA++;
            matchRemA--;
        } else { // Team B's turn
            if (favA[i] == '1') matchWonB++;
            matchRemB--;
        }
        if (matchWonA > matchWonB + matchRemB) {
            matchFA = i + 1;
            break;
        }
    }

    matchWonA = 0, matchWonB = 0, matchRemA = 5, matchRemB = 5;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            if (favB[i] == '1') matchWonA++;
            matchRemA--;
        } else {
            if (favB[i] == '1') matchWonB++;
            matchRemB--;
        }
        if (matchWonB > matchWonA + matchRemA) {
            matchFB = i + 1;
            break;
        }
    }

    cout << min(matchFA, matchFB) << endl;
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
#include <bits/stdc++.h>
#include "set"
#include <cmath>
#include "unordered_map"
#include "algorithm"
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

int MOD = 1e9+7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(int n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

int power(int a, int b){
    if (b == 0) return 1;
    int x  = power(a, b/2);
    if (b % 2 == 0){
        return x * x;
    } else{
        return x * x * a;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int powermod(int x, int y, int p) {
    int res = 1;
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

int bitCount(int num) {
    return num ? (int) log2(num) + 1 : 0;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    int total = 0;
    rep(i, 0, n) {
        cin >> a[i];
        total += a[i];
    }

    vi a1(n - 1), a2(n - 1);
    for (int i = 0; i < n - 1; ++i) a1[i] = a[i];
    for (int i = 1; i < n; ++i) a2[i - 1] = a[i];

    int maxi1 = a1[0], curr1 = a1[0];
    for (int i = 1; i < n - 1; ++i) {
        curr1 = max(a1[i], curr1 + a1[i]);
        maxi1 = max(maxi1, curr1);
    }

    int maxi2 = a2[0], curr2 = a2[0];
    for (int i = 1; i < n - 1; ++i) {
        curr2 = max(a2[i], curr2 + a2[i]);
        maxi2 = max(maxi2, curr2);
    }

    int maxi = max(maxi1, maxi2);
    cout << ((maxi < total) ? "Yes" : "No") << endl;
}


int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

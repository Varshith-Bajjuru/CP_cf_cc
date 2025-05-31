#include <bits/stdc++.h>
#include "set"
#include <cmath>
#include "unordered_map"
#include "algorithm"
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

int MOD = 998244353;

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
    int k, x;
    cin >> k >> x;
    auto prefix_sum = [&](int i) {
        // sum from get_val(0) to get_val(i)
        if (i < k) {
            // sum of first (i+1) natural numbers
            return 1LL * (i + 1) * (i + 2) / 2;
        } else {
            // full increasing part: sum_1 = k*(k+1)/2
            // decreasing part: sum_2 = (k-1 + k - (i - k)) * (i - k + 1) / 2
            // which is sum of arithmetic series from get_val(k) to get_val(i)
            long long sum_1 = 1LL * k * (k + 1) / 2;
            int rem = i - k + 1;
            long long first = k - 1;
            long long last = k - rem;
            long long sum_2 = (first + last) * rem / 2;
            return sum_1 + sum_2;
        }
    };

    int lo = 0, hi = 2 * k - 2, ans = 2 * k - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (prefix_sum(mid) >= x) {
            ans = mid + 1;  // since `i` is 0-based
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
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

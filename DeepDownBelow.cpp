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

bool f(int mid, map<int, int> &mp) {
    int curr = mid;
    for (auto &[key, cnt] : mp) {
        if (curr-1 > key) {
            curr += cnt;
        } else {
            return false;
        }
    }
    return true;
}

int helper(map<int, int> &mp) {
    int left = 1, right = 2e9, ans = 2e9;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (f(mid,mp)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vi curr(x);
        for (int j = 0; j < x; ++j) {
            cin >> curr[j];
            curr[j] -= (j + 1);
        }
        v.push_back(curr);
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int num = *max_element(all(v[i]));
        mp[num] += (int)v[i].size();
    }
    cout << helper(mp) << endl;
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

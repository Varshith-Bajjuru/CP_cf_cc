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

int lowerBound(const vi &a, int money,int day) {
    int left = 0, right = (int)a.size() - 1;
    if (money < a[0]  + day) return -1;
    if (money > a[right] + day*(right+1)) return (int)a.size();
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] + day*(mid+1) >= money) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    vector<long long> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = a[i] + prefix[i - 1];
    }
    long long ans = 0;
    int prevDay = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (prefix[i] > x) continue;
        int currDay = (x - prefix[i]) / (i + 1);
        ans += (i + 1) * (currDay - prevDay);
        prevDay = currDay;
    }
    cout << ans << endl;
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

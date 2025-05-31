#include <bits/stdc++.h>
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
#define endl '\n'

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
        n = n / 10;
        cnt++;
    }
    return cnt;
}

int power(int a, int b){
    if (b == 0) return 1;
    int x = power(a, b / 2);
    if (b % 2 == 0){
        return x * x;
    } else {
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

int bs(int target, vi &a) {
    int left = 0,right = a.size()-1;

    while (left <= right){
        int mid = left + (right-left)/2;
        if (a[mid] == target){
            return mid;
        }
        if (a[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return -1;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi prefix(n), suffix(n);
    prefix[0] = a[0];
    suffix[n - 1] = a[n - 1];

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int idx = bs(suffix[i], prefix);
        if (idx != -1 && i > idx) {
            ans = max(ans, (n-i) + idx + 1);
        }
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

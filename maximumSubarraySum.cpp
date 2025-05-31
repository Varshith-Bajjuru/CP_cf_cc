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
typedef long long ll;

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

int maxSum(vi &a) {
    int curr = INT_MIN, maxi = INT_MIN;
    for (int i : a) {
        curr = max(i, curr + i);
        maxi = max(maxi, curr);
    }
    return maxi;
}

void bs(vi &a,int idx,int k){
    int left = -1e18,right = k;
    while (left <= right){
        int mid = left + (right - left)/2;
        a[idx] = mid;
        int sum = maxSum(a);
        if (sum == k){
            return;
        }
        if (sum < k){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n),idxs;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (s[i] == '0'){
            a[i] = -1e18;
            idxs.push_back(i);
        }
    }

    if (maxSum(a) > k){
        cout << "No" << endl;
        return;
    }

    if (maxSum(a) == k) {
        cout << "Yes" << endl;
        for (int val : a) cout << val << " ";
        cout << endl;
        return;
    }
    if (idxs.empty()){
        cout << "No" << endl;
        return;
    }

    vi noIdxs;
    for (int i = 0; i < idxs.size(); ++i) {
        vi b = a;
        b[idxs[i]] = k;
        if (maxSum(b) == k){
            cout << "Yes" << endl;
            for (int j = 0; j < n; ++j) {
                cout << b[j] << " ";
            }
            cout << endl;
            return;
        }else{
            noIdxs.push_back(idxs[i]);
        }
    }
    if (!noIdxs.empty()){
        bs(a,noIdxs[0],k);
    }
    cout << "Yes" << endl;
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
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
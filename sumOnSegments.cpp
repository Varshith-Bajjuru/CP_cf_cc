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

vi sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    vi primes;
    for (int i = 0; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}

pii maxAndMinSubarraySumInRange(const vector<int>& nums, int left, int right) {
    int maxSum = INT_MIN, maxEndingHere = 0;
    int minSum = INT_MAX, minEndingHere = 0;

    for (int i = left; i <= right; ++i) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSum = max(maxSum, maxEndingHere);

        minEndingHere = min(nums[i], minEndingHere + nums[i]);
        minSum = min(minSum, minEndingHere);
    }

    return {maxSum, minSum};
}

// Function to compute prefix min and max sums in a range
pii minMax(const vi &a, int left, int right) {
    int mini = INT_MAX, maxi = INT_MIN, prefix = 0;
    for (int i = left; i <= right; ++i) {
        prefix += a[i];
        mini = min(mini, prefix);
        maxi = max(maxi, prefix);
    }

    return {mini, maxi};
}

// Helper function to print set of integers
void print(set<int> &st) {
    cout << st.size() << endl;
    for (int i : st) cout << i << " ";
    cout << endl;
}

// Main problem-solving function
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int pivot = -1;
    // Read array and identify first non-1/-1 value (pivot)
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)
            pivot = i;
    }
    set<int> ans;
    ans.insert(0); // base case
    if (pivot != -1) {
        if (pivot == 0 && n > 1) {
            pii p = maxAndMinSubarraySumInRange(a, 1, n - 1);
            for (int i = min(p.first, p.second); i <= max(p.first, p.second); ++i)
                ans.insert(i);

            pii p2 = minMax(a, 1, n - 1);
            for (int i = a[pivot] + p2.first; i <= a[pivot] + p2.second; ++i)
                ans.insert(i);

        } else if (pivot == n - 1 && n > 1) {
            pii p = maxAndMinSubarraySumInRange(a, 0, n - 2);
            for (int i = min(p.first, p.second); i <= max(p.first, p.second); ++i)
                ans.insert(i);

            pii p2 = minMax(a, 0, n - 2);
            for (int i = a[pivot] + p2.first; i <= a[pivot] + p2.second; ++i)
                ans.insert(i);

        } else if (pivot > 0 && pivot < n - 1) {
            pii p1 = maxAndMinSubarraySumInRange(a, 0, pivot - 1);
            pii p2 = maxAndMinSubarraySumInRange(a, pivot + 1, n - 1);
            for (int i = min(p1.first, p1.second); i <= max(p1.first, p1.second); ++i)
                ans.insert(i);
            for (int i = min(p2.first, p2.second); i <= max(p2.first, p2.second); ++i)
                ans.insert(i);

            pii p3 = minMax(a, 0, pivot - 1);
            pii p4 = minMax(a, pivot + 1, n - 1);
            for (int i = a[pivot] + min(p3.first, min(p4.first,p3.first+p4.first)); i <= a[pivot] + max(p3.second,max(p4.second,p3.second+p4.second)); ++i)
                ans.insert(i);
        }

    } else {
        // No pivot found: only 1 and -1 present
        pii p = maxAndMinSubarraySumInRange(a, 0, n - 1);
        for (int i = min(p.first, p.second); i <= max(p.first, p.second); ++i)
            ans.insert(i);
    }

    print(ans);
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
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

int oper(const vector<pair<int, int>> &positions, const vector<vector<int>> &grid) {
    set<pair<int,int>> posSet(positions.begin(), positions.end());
    for (auto [x, y] : positions) {
        for (auto [dx, dy] : vector<pair<int,int>>{{0,1},{1,0},{0,-1},{-1,0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                if (posSet.count({nx, ny})) {
                    return 2;
                }
            }
        }
    }
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    map<int, vector<pair<int, int>>> number_positions;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            number_positions[grid[i][j]].emplace_back(i, j);
        }
    }
    if (n == 1 && m == 1) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    bool isTwo = false;
    for (auto &[num, positions] : number_positions) {
        int val = oper(positions, grid);
        ans += val;
        if (val == 2) isTwo = true;
    }
    cout << ans - (isTwo ? 2 : 1) << '\n';
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